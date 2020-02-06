#include "Server.h"
#include <nlohmann/json.hpp>

#include "GameSession.h"
#include "User.h"
#include "UserList.h"

#include "GameSessionManager.cpp"

#include <atomic>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <thread>
#include <vector>

static std::atomic<bool> exit_thread_flag{false};
static const std::string SERVER_CONFIGURATION_FILE_LOCATION = "config/ServerProperties.json";
static UserList usersInMainLobby;
static std::string globalMessage = "";

//main thread
static void OnDisconnect(networking::Connection);
static void OnConnect(networking::Connection);
static std::string getConfigurationFilePath(int, char* []);
static void checkValidConfigurationFile(const nlohmann::json&);

//message thread
static void handleMessages(networking::Server&);
static std::vector<networking::Message> processMessages(networking::Server&, const std::deque<networking::Message>&);
static std::deque<networking::Message> buildOutgoing(const std::vector<networking::Message>&);

int main(int argc, char* argv[]){

	//Read Json
	std::string configurationFilePath = getConfigurationFilePath(argc, argv);
	std::ifstream configurationFile(configurationFilePath, std::ifstream::in);

	nlohmann::json configuration = nlohmann::json::parse(configurationFile);

	checkValidConfigurationFile(configuration);

	unsigned short port = configuration["DefaultPort"];
	std::string htmlpath = configuration["HTML Location"];

	std::cout << "starting server \nport: " << port << "\nhtml path: " << htmlpath << '\n';

	//Configure Server
    std::ifstream htmlFile{htmlpath};
	std::string htmlFileStr{std::istreambuf_iterator<char>(htmlFile),std::istreambuf_iterator<char>()};
    networking::Server server{port, htmlFileStr, OnConnect, OnDisconnect};

	std::thread messageHandling(handleMessages, std::ref(server));

	//while server up, process messages
	std::string message = "";
	do{
		globalMessage = message;
		std::getline(std::cin, message);
	} while (message != "shutdown");

	exit_thread_flag = true;
	messageHandling.join();

	return 0;
}

//teacher provided functions
static void OnConnect(networking::Connection c) {
	std::cout << "New connection found: " << c.id << "\n";

	UserId id(c.id);
	usersInMainLobby.addUser(id);
}

//teacher provided functions
static void OnDisconnect(networking::Connection c) {
	std::cout << "Connection lost: " << c.id << "\n";

	UserId id(c.id);
	usersInMainLobby.removeUser(id);
}

static std::string getConfigurationFilePath(int argc, char* argv[]){
	if(argc <= 1){
		return SERVER_CONFIGURATION_FILE_LOCATION;
		//TODO: if config file does not exist, create a default one
	}
	else{
		return argv[1];
	}
}

static void checkValidConfigurationFile(const nlohmann::json &configurationFile) {
	
	auto port = configurationFile.at("DefaultPort");
	std::string htmlpath = configurationFile.at("HTML Location");

	//string to short conversion check
	if(port.get<unsigned short>() != port.get<std::intmax_t>()){
		std::cout << "Port out of range\n";
	    std::exit(-1);
	}

	//html path check for valid file
	if(access(htmlpath.c_str(), R_OK) == -1){
	    std::cout << "Unable to open HTML index file: " << htmlpath << "\n";
        std::exit(-1);
	}
	
}

#pragma region ClientServerNetworkingThread

static void handleMessages(networking::Server& server){
	
	while (exit_thread_flag == false) {

		bool errorWhileUpdating = false;

		try {
			server.update();
		} 
		catch (std::exception& e) {
			std::cerr << "Exception from Server update:\n"
						<< " " << e.what() << "\n\n";
			errorWhileUpdating = true;
		}

		auto incoming = server.receive();
		
		std::vector<networking::Message> returnMessage = processMessages(server, incoming);

		auto outgoing = buildOutgoing(returnMessage);

		server.send(outgoing);

		if (errorWhileUpdating) {
			break;
		}

		sleep(1);
  	}

	return;
}

static std::vector<networking::Message> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::vector<networking::Message> result;

	for (networking::Message message : incoming) {

		// TODO Mzegar: Testing, this should go somewhere else
		// Figure out somewhere else to put this and refactor
		// Depending on our command structure in the future, we may only need to lookup the user once here 
		// (we do same lookups at the bottom too) Ex. User owner = getUserFrom...
		UserId id(message.connection.id);
		std::string name = std::string();
		User user = usersInMainLobby.getUser(id);
		if (message.connection.id == user.getId() && !user.getName().empty()) {
			name = user.getName();
		}

		if (!name.empty()) {
			std::cout << name << "> " << message.text << "\n";
		} else {
			std::cout << message.connection.id << "> " << message.text << "\n";
		}

		//ad-hoc message processing
		if (message.text == "quit") {
			server.disconnect(message.connection);
		} 
		else if (message.text == "shutdown") {
			std::cout << "shutdown game\n";
			//kick all players
		} 
		else if (message.text == "start game"){
			std::cout << "start game\n";
		} 
		else if (message.text == "create lobby"){
			GameSession init = GameSessionManager::createGameSession(user);
			Invitation code = init.getInvitationCode();
			result.push_back(networking::Message{message.connection, "Your Invitation Code is: " + code.toString()});

			std::cout << "creating lobby " << code.toString() << '\n';
		}
		else if (message.text.find("join") != std::string::npos) {
			std::string inviteCode = message.text.substr(5);

			if(GameSessionManager::joinGameSession(user, inviteCode)){
				std::cout << "joining lobby " << inviteCode << '\n';
			}
			else {
				std::cout << "lobby does not exist\n";
			}

		} 
		else if (message.text == "/username") {
			// TODO Mzegar: figure out where to put commands, alongside making a better system for creating commands...
			user.setName("TestName");
		}
		else {
			//find session based on connection id
			//send message into game

			//for example something 
			//game[connection].message = blahblahblah
		
			result.push_back(networking::Message{message.connection, message.text});
		}
	}

	//update all games

	//process messages based on game logic

	//get reply of all games

	return result;
}

//teacher provided functions
static std::deque<networking::Message> buildOutgoing(const std::vector<networking::Message>& returnMessage) {
	std::deque<networking::Message> outgoing;

	//dummy code
	for(auto& message : returnMessage){
		std::ostringstream log;

		User messageOwner = usersInMainLobby.getUser(message.connection.id);
		if(GameSessionManager::inSession(messageOwner)) {
			//send to everyone in session or not depending on game logic
		}
		else {
			//send only to them
			log << messageOwner.getId() << "> " << message.text << '\n';
			outgoing.push_back({networking::Connection{messageOwner.getId()}, log.str()});
		}
	}

	if(globalMessage != "") {
		for(auto& entry : usersInMainLobby){
			User user = entry.second;

			outgoing.push_back({networking::Connection{user.getId()}, globalMessage});
		}

		globalMessage = "";
	}

	return outgoing;
}
#pragma endregion