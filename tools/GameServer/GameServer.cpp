#include "Server.h"

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>

std::vector<networking::Connection> clients;

void onDisconnect(networking::Connection);
void onConnect(networking::Connection);

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
    networking::Server server{std::stoi(port), htmlpath, OnConnect, OnDisconnect};

	//Select Game
    std::string games[] {"game1.json", "game2.json", "game3.json"}; //keep this in json as well?
    std::cout << "\nPlease select a game\n1. Game 1\n2. Game 2\n3. Game 3\n";
    int gameIndex;

    do{
    	std::cin >> gameIndex;
	}while(gameIndex <= 0 || gameIndex > 3);

 	std::cout << "Selected Game: " << games[gameIndex-1] << "\n";

    //Prepare Lobby in background

    //wait for "start game"?

    //get all users

    //start game with users

	//Wait until End signal

	//select another game

	return 0;
}

//teacher provided functions
void
OnConnect(networking::Connection c) {
  std::cout << "New connection found: " << c.id << "\n";
  clients.push_back(c);
}

//teacher provided functions
void
OnDisconnect(networking::Connection c) {
  std::cout << "Connection lost: " << c.id << "\n";
  auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
  clients.erase(eraseBegin, std::end(clients));
}