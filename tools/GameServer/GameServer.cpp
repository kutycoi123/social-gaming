#include "Server.h"

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>

std::vector<networking::Connection> clients;

void onDisconnect(networking::Connection);
void onConnect(networking::Connection);
std::string getHTTPMessage(const char*);

int main(int argc, const char* argv[]){
	
	const std::string SERVER_CONFIGURATION_FILE_LOCATION = "config/ServerProperties.json";

	//Read Json
	std::ifstream configurationFile(SERVER_CONFIGURATION_FILE_LOCATION, std::ifstream::in);
	
	nlohmann::json configuration = nlohmann::json::parse(configurationFile);

	std::string port = configuration["DefaultPort"];
	std::string htmlpath = configuration["HTML Location"];
	

	std::cout << "starting server \nport: " << port << "\nhtml path: " << htmlpath << '\n';

	//Configure Server
	//string to short conversion check
	//html path check for valid file
    networking::Server server{std::stoi(port), htmlpath, onConnect, onDisconnect};


	//Select game and prepare lobby
	//Until "Start"
	//Wait until End signal
	//reselect game

	return 0;
}

//teacher provided functions
void
onConnect(networking::Connection c) {
  std::cout << "New connection found: " << c.id << "\n";
  clients.push_back(c);
}

//teacher provided functions
void
onDisconnect(networking::Connection c) {
  std::cout << "Connection lost: " << c.id << "\n";
  auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
  clients.erase(eraseBegin, std::end(clients));
}