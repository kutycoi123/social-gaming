#include "Server.h"
#include <nlohmann/json.hpp>

#include "GameSessionManager.h"
#include "GameServerConfiguration.h"
#include "User.h"

#include "Command.h"

#include <atomic>
#include <queue>
#include <iostream>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <unistd.h>

struct GlobalMessage{
	std::string message;
	//something to specifiy private message, broadcast to specifiv session, broadcast globally (all sessions)
	//maybe user id?, session id?
};

// TODO: Mzegar consider moving this into some component
static UserList users;

static std::atomic<bool> exit_thread_flag{false};
static const std::string SERVER_CONFIGURATION_FILE_LOCATION = "config/ServerProperties.json";
 
static GlobalMessage globalMessage = {""};
static bool joinSession(const std::string&, User);

//main thread
static void OnDisconnect(networking::Connection);
static void OnConnect(networking::Connection);
static std::string getConfigurationFilePath(int, char* []);

//message thread
static void handleMessages(networking::Server&);
static std::deque<networking::Message> gameServerUpdate(networking::Server&, const std::deque<networking::Message>&);
static std::deque<networking::Message> SendMessageToSession();
static std::deque<networking::Message> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming);

//player authentication. 

int main(int argc, char* argv[]){

	//Read Json
	std::string configurationFilePath = getConfigurationFilePath(argc, argv);
	std::ifstream configurationFile(configurationFilePath, std::ifstream::in);
	nlohmann::json configuration = nlohmann::json::parse(configurationFile);

	GameServerConfiguration::configureServer(configuration);

	unsigned short port = GameServerConfiguration::getPort();
	std::string htmlContents = GameServerConfiguration::getHtmlFileContent();

	std::cout << "starting server on port: " << port << '\n';

	//Configure Server
    networking::Server server{port, htmlContents, OnConnect, OnDisconnect};


	std::thread messageHandling(handleMessages, std::ref(server));

	//while server up, process messages
	std::string message;
	do{
		globalMessage.message = message;
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
	users.onConnect(id);
}

//teacher provided functions
static void OnDisconnect(networking::Connection c) {
	std::cout << "Connection lost: " << c.id << "\n";
	
	UserId id(c.id);
	users.onDisconnect(id);
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
		

		auto outgoing = gameServerUpdate(server, incoming);
	 

		//auto outgoing = SendMessageToSession();
		server.send(outgoing);
	 
		if (errorWhileUpdating) {
			break;
		}

		sleep(1);
  	}

	return;
}

std::deque<networking::Message> SendMessageToSession() {
	std::deque<networking::Message> commandResult;

    for (auto& inviteGameElement : GameSessionManager::invitationToGameSessionMap) {
        for (auto& user : users.getUsersInSession(inviteGameElement.second.getInvitationCode())) {
            std::queue messages = inviteGameElement.second.getMessages();

            int total = messages.size();
            std::cout << "Total messages:" << total << std::endl;
            for (int i = 0; i < total; ++i) {
                std::cout << "Sending all messages to user" << std::endl;
                commandResult.push_back(networking::Message{{user.get().getUserIdValue()}, messages.front()});
            }
        }
        inviteGameElement.second.clearMessages();
    }
 
	return commandResult;
}
	 
//paramters connection Id message
static void AddMessageToCorrectSession(const uintptr_t userID, const std::string &message) {

	 auto iter =  GameSessionManager::userToInviteCode.find(userID);
	std::cout<<"looking for invitation"<<"\n";
	if(iter != GameSessionManager::userToInviteCode.end()) {
			std::cout<<"found invitation"<<"\n";

			auto it = GameSessionManager::invitationToGameSessionMap.find(iter->second);
				
			std::cout<<iter->second.toString()<<std::endl;
				
			if(it == GameSessionManager::invitationToGameSessionMap.end()) {
					std::cout<<"can't find session of user"<<"\n";
			}
				else {
					std::cout<<"added message to session queue";
					it->second.addMessages(message);
				}

		} 
 }

static std::deque<networking::Message> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::deque<networking::Message> commandResult;
	
	
	for (networking::Message message : incoming) {

        UserId id(message.connection.id);
        std::optional<User> user = users.getUser(id);

        std::vector<std::string> commandParams = Command::getCommandArguments(message.text);
        std::string firstCommandParam = commandParams.empty() ? std::string() : commandParams.at(0);
        GameServerConfiguration::CommandType command = Command::getCommandType(message.text);

		switch (command)
		{
			case GameServerConfiguration::CommandType::DISCONNECT:
				{
					server.disconnect(message.connection);
				}
			break;
			case GameServerConfiguration::CommandType::SHUTDOWN:
				{
                    auto invitation = Invitation::createInvitationFromStringInput(firstCommandParam);
                    if (GameSessionManager::endGameSession(invitation, users)) {
                        message.text.append("\n Ending game!");
                    } else {
                        message.text.append("\n Unable to end game!");
                    }
				}
			break;
			case GameServerConfiguration::CommandType::START_GAME:
				{
                    auto invitation = Invitation::createInvitationFromStringInput(firstCommandParam);
                    if (GameSessionManager::startGameInGameSession(invitation)) {
                        message.text.append("\n Starting game!");
                    } else {
                        message.text.append("\n Unable to start game!");
                    }
				}
			break;
			case GameServerConfiguration::CommandType::CREATE_SESSION:
				{
                    std::optional<GameSession> session = GameSessionManager::createGameSession(user.value());
                    if (session.has_value()) {
                        message.text.append("\n Creating session: \n");
                        message.text.append(" Here is the invitation code for your session: ");
                        message.text.append(session.value().getInvitationCode().toString());
                    } else {
                        message.text.append("\n Error, Could not create session!");
                    }
				}
			break;
			case GameServerConfiguration::CommandType::JOIN_SESSION:
				{
                    auto userProvidedCode = Invitation::createInvitationFromStringInput(firstCommandParam);
                    auto userRef = users.getUserRef(user.value().getUserId());
                    if (userRef.has_value() && GameSessionManager::joinGameSession(userRef.value(), userProvidedCode)) {
                        message.text.append("\n Joining session!");
                    } else {
                        message.text.append("\n Unable to join session!");
                    }
				}
			break;
			case GameServerConfiguration::CommandType::USERNAME:
				{
                    auto userRef = users.getUserRef(id);
                    if (!commandParams.empty() && userRef.has_value()) {
                        userRef.value().get().setUserName(UserName(firstCommandParam));
                    } else {
                        message.text.append("\n Error, unable to set username!");
                    }
				}
			break;
			case GameServerConfiguration::CommandType::HELP:
				{
					message.text.append("\n List of user commands: \n");
					message.text.append(Command::getAllCommandDescriptions());
				}
			break;
			case GameServerConfiguration::CommandType::NULL_COMMAND:
			    {
			        
				}
			break;
			default:
				{
					//do nothing
				}
			break;
			}

            commandResult.push_back(networking::Message{message.connection, message.text.insert(0,user.value().getUserNameValue() + ": ")});

    }

	return commandResult;
}

static std::deque<networking::Message> getGlobalMessages(){
	std::deque<networking::Message> result {};
	
	if(globalMessage.message != ""){

		for(auto& entry : users){
			User user = entry.second;
			result.push_back({networking::Connection{user.getUserIdValue()}, globalMessage.message});
		}

		globalMessage.message = "";
	}

	return result;
}

static std::deque<networking::Message> gameServerUpdate(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::deque<networking::Message> allMessages = {};

	std::deque<networking::Message> globalMessages = getGlobalMessages();
	allMessages.insert(allMessages.end(), globalMessages.begin(), globalMessages.end());

	//doesn't really make sense for command messages to be broadcasted to everyone, so only the person creating the command needs to see the server reply
	std::deque<networking::Message> commandMessages = processMessages(server, incoming);
	allMessages.insert(allMessages.end(), commandMessages.begin(), commandMessages.end());

	//TODO: update all games based on game logic (probs in gamesessionmanager)

	std::deque<networking::Message> gameMessages = GameSessionManager::getAllGameMessages();
	allMessages.insert(allMessages.end(), gameMessages.begin(), gameMessages.end());
	
	std::deque<networking::Message> lobbyMessages = GameSessionManager::getAllLobbyMessages();
	allMessages.insert(allMessages.end(), lobbyMessages.begin(), lobbyMessages.end());

	return allMessages;
}

#pragma endregion
