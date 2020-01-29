#include "Server.h"

#include <nlohmann/json.hpp>

#include <atomic>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <thread>

struct MessageResult {
  std::string result;
  bool shouldShutdown;
};

static std::atomic<bool> exit_thread_flag{false};
static const std::string SERVER_CONFIGURATION_FILE_LOCATION = "config/ServerProperties.json";
static std::vector<networking::Connection> clients;

static void OnDisconnect(networking::Connection);
static void OnConnect(networking::Connection);
static MessageResult processMessages(networking::Server&, const std::deque<networking::Message>&);
static std::deque<networking::Message> buildOutgoing(const std::string&);
static std::string getConfigurationFilePath(int, char* []);
static void checkValidConfigurationFile(const nlohmann::json&);
static void handleMessages(networking::Server&);

int main(int argc, char* argv[]){
	
	//Read Json
	std::ifstream configurationFile(getConfigurationFilePath(argc, argv), std::ifstream::in);

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
	clients.push_back(c);
}

//teacher provided functions
static void OnDisconnect(networking::Connection c) {
	std::cout << "Connection lost: " << c.id << "\n";
	auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
	clients.erase(eraseBegin, std::end(clients));
}

//teacher provided functions
static MessageResult processMessages(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::ostringstream result;
	bool quit = false;

	for (auto& message : incoming) {
		if (message.text == "quit") {
			server.disconnect(message.connection);
		} 
		else if (message.text == "shutdown") {
			std::cout << "Shutting down.\n";
			quit = true;
		} 
		else {
			result << message.connection.id << "> " << message.text << "\n";
		}
	}
	return MessageResult{result.str(), quit};
}

//teacher provided functions
static std::deque<networking::Message> buildOutgoing(const std::string& log) {
  std::deque<networking::Message> outgoing;
  for (auto client : clients) {
    outgoing.push_back({client, log});
  }
  return outgoing;
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
		auto [log, shouldQuit] = processMessages(server, incoming);
		auto outgoing = buildOutgoing(log);
		server.send(outgoing);
		
		//if should quit and is owner of a game and game is running, close the game
		if(shouldQuit){
			std::cout << "shutdown game\n";
		}

		if (errorWhileUpdating) {
			break;
		}

		sleep(1);
  	}

	return;
}