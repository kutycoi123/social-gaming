#include "GameSession.h"
#include "Server.h"
#include <nlohmann/json.hpp>

#include "GameSessionManager.cpp"
#include "User.h"

#include "ProcessCommand.h"

#include <atomic>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <thread>
#include <vector>


struct MessageInfo{
	networking::Message message;
	//information about which lobby to send message to
};

static std::atomic<bool> exit_thread_flag{false};
static const std::string SERVER_CONFIGURATION_FILE_LOCATION = "config/ServerProperties.json";
static std::vector<networking::Connection> clients;
static std::vector<User> users;

static std::vector<std::string> strVector ;
static std::vector<std::string> splitCommand(std::string s);
const int FIRST_COMMAND = 0;
const int SECOND_COMMAND = 1;

//main thread
static void OnDisconnect(networking::Connection);
static void OnConnect(networking::Connection);
static std::string getConfigurationFilePath(int, char* []);
static void checkValidConfigurationFile(const nlohmann::json&);

//message thread
static void handleMessages(networking::Server&);
static std::vector<MessageInfo> processMessages(networking::Server&, const std::deque<networking::Message>&);
static std::deque<networking::Message> buildOutgoing(const std::vector<MessageInfo>&);

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
		std::cin >> message;
	} while (message != "shutdown");

	exit_thread_flag = true;
	messageHandling.join();

	return 0;
}

//teacher provided functions
static void OnConnect(networking::Connection c) {
	std::cout << "New connection found: " << c.id << "\n";

	// TODO: Mzegar think of some way to handle these two together
	clients.push_back(c);
	users.push_back(User(c.id));
}

//teacher provided functions
static void OnDisconnect(networking::Connection c) {
	std::cout << "Connection lost: " << c.id << "\n";

	// TODO: Mzegar think of some way to handle these two together
	// Also use std methods of iterating over this when refactor comes in
	for (int i = users.size(); i >= 0; --i)
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
		std::vector<MessageInfo> returnMessage = processMessages(server, incoming);

		auto outgoing = buildOutgoing(returnMessage);

		server.send(outgoing);

		if (errorWhileUpdating) {
			break;
		}

		sleep(1);
  	}

	return;
}

static std::vector<MessageInfo> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::vector<MessageInfo> result;

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

		std::string text = message.text;

		ProcessCommand evaluateText;

		ProcessCommand evaluateMessage;		

		ProcessCommand::CommandType serverCommand;

		strVector = splitCommand(text);
		
		serverCommand = evaluateMessage.evaluateCommand(strVector[FIRST_COMMAND]);

		switch (serverCommand)
		{
		case ProcessCommand::CommandType::QUIT:
		{
			std::cout << "quit game\n";
			server.disconnect(message.connection);
			break;
		}
		case ProcessCommand::CommandType::SHUTDOWN:
		{
			std::cout << "shutdown game\n";
			break;
		}
		case ProcessCommand::CommandType::START_GAME:
		{
			std::cout << "start game\n";
			break;
		}
		case ProcessCommand::CommandType::CREATE_LOBBY:
		{
			GameSession init = GameSessionManager::createGameSession(1);
			Invitation code = init.getInvitationCode();
			result.push_back(MessageInfo{networking::Message{message.connection, "Your Invitation Code is: " + code.toString()}});
			std::cout << "creating lobby " << code.toString() << '\n';
			break;
		}
		case ProcessCommand::CommandType::JOIN_LOBBY:
		{

			std::cout << "joining lobby ";
			break;
		}
		case ProcessCommand::CommandType::USERNAME:
		{
			for (auto& user : users) {
				if (message.connection.id == user.getId()) {
					user.setName("Testing");
				}
			}
		break;
		}
		case ProcessCommand::CommandType::NULL_COMMAND:
		{
			std::cout << "Error, Invalid user command" << '\n';
		break;
		}

		}
	}

	//update all games

	//process messages based on game logic

	//get reply of all games

	return result;
}
std::vector<std::string> splitCommand(std::string s){
    
    std::istringstream iss(s);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
    return results;

 };

//teacher provided functions
static std::deque<networking::Message> buildOutgoing(const std::vector<MessageInfo>& returnMessage) {
	std::deque<networking::Message> outgoing;

	//only push to clients if they are in the same lobby

	//dummy code
	std::ostringstream log;

	for(auto& message : returnMessage){
		networking::Message rawMessage = message.message;
		log << rawMessage.connection.id << "> " << rawMessage.text << '\n';
	}

	for (auto& client : clients) {
		outgoing.push_back({client, log.str()});
	}

	return outgoing;
}

#pragma endregion