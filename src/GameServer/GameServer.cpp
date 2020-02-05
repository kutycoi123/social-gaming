#include "GameSession.h"
#include "Server.h"
#include <nlohmann/json.hpp>

#include "GameSessionManager.cpp"
#include "User.h"

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
static std::vector<networking::Connection> clients;
static std::vector<User> users;
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
static User connectionIdToUser(uintptr_t);

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
		std::cin >> message;
	} while (message != "shutdown");

	exit_thread_flag = true;
	messageHandling.join();

	return 0;
}

//teacher provided functions
static void OnConnect(networking::Connection c) {
	std::cout << "New connection found: " << c.id << "\n";

	users.push_back(User(c.id));
}

//teacher provided functions
static void OnDisconnect(networking::Connection c) {
	std::cout << "Connection lost: " << c.id << "\n";

	// TODO: Use std methods of iterating over this when refactor comes in
	for (int i = 0; i < users.size(); i++)
	{
		if (users.at(i).getId() == c.id) {
			users.erase(users.begin() + i);
		}
	}

	auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
	clients.erase(eraseBegin, std::end(clients));
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

		// TODO Mzegar: Use profs iteration when refactor happens
		// Figure out somewhere else to put this
		std::string name = std::string();
		for (auto& user : users) {
			if (message.connection.id == user.getId() && !user.getName().empty()) {
				name = user.getName();
			}
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
			User owner = connectionIdToUser(message.connection.id);
	
			GameSession init = GameSessionManager::createGameSession(owner);
			Invitation code = init.getInvitationCode();
			result.push_back(networking::Message{message.connection, "Your Invitation Code is: " + code.toString()});

			std::cout << "creating lobby " << code.toString() << '\n';
		}
		else if (message.text == "join lobby") {
			std::cout << "joining lobby 1\n";

		} 
		else if (message.text == "/username") {
			// TODO Mzegar: figure out where to put commands, alongside making a better system for creating commands...
			// Use profs iteration when refactor happens
			for (auto& user : users) {
				// TODO: Maybe a hash table makes sense for this in the future, regardless template code
				if (message.connection.id == user.getId()) {
					user.setName("Testing");
				}
			}
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

		User messageOwner = connectionIdToUser(message.connection.id);

		if(GameSessionManager::inSession(messageOwner)) {
			//send to everyone in session
		}
		else {
			//send only to them
			log << message.connection.id << "> " << message.text << '\n';

			//TODO: Add method to user for creating connection?
			outgoing.push_back({networking::Connection{message.connection.id}, log.str()});
		}
	}

	if(globalMessage != ""){
		for(User user : users){
			outgoing.push_back({networking::Connection{user.connection.id}, globalMessage});
		}

		globalMessage = "";
	}

	return outgoing;
}

static User connectionIdToUser(uintptr_t connectionId){
	for(auto& user : users){
		if(user.getId() == connectionId){
			return user;
		}
	}

	throw std::runtime_error("no such user");
}

#pragma endregion