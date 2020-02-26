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
static std::pair<bool, Invitation> createSession(networking::Message, User);
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

		std::string text = message.text;

		UserId id(message.connection.id);
        std::optional<User> user = users.getUser(id);

		switch (Command::getCommandType(text))
		{
			case GameServerConfiguration::CommandType::DISCONNECT:
				{
					server.disconnect(message.connection);
				}
			break;
			case GameServerConfiguration::CommandType::SHUTDOWN:
				{
					std::cout << "shutdown game\n";
					// TODO: Requires Matthew's User MR
				}
			break;
			case GameServerConfiguration::CommandType::START_GAME:
				{
					//print out those string games.
					//find gameSession based on code, push back message to queue



					//AddMessageToCorrectSession(message.connection.id, "start game\n");
					std::cout << "start game\n";
					// TODO: Requires Matthew's User MR
				}
			break;
			case GameServerConfiguration::CommandType::CREATE_SESSION:
				{
                    std::pair<bool, Invitation> session = createSession(message, user.value());
                    if (!session.first){
                        message.text.append(" Error, Could not create lobby!");
                    }
                    else
                    {
                        message.text.append("\n Creating lobby: \n");
                        message.text.append(" Here is the invitation code for your lobby: ");
                        message.text.append(session.second.toString());
                    }
				}
			break;
			case GameServerConfiguration::CommandType::JOIN_SESSION:
				{
                    if(!joinSession(text, user.value())){
                        message.text.append(" Error, cannot join lobby!");
                    }
                    else{
                        message.text.append("\n joining lobby!");
                    }
				}
			break;
			case GameServerConfiguration::CommandType::USERNAME:
				{
                    auto name = Command::getCommandArguments(text);
                    auto userRef = users.getUserRef(id);
                    if (!name.empty() && userRef.has_value()) {
                        userRef.value().get().setUserName(UserName(name.at(0)));
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
                    std::cout << text << '\n';
                    commandResult.push_back(networking::Message{message.connection, message.text});
				}
			break;
			default:
				{
					//do nothing
				}
			break;
			}
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

std::pair<bool, Invitation> createSession(networking::Message m, User user){
	GameSession init = GameSessionManager::createGameSession(user);
	GameSession &initRef = init;

	Invitation code = initRef.getInvitationCode();
	//TODO: add mapUserIDToInvitation

	//investigate  GameSessionManager::_invitationToGameSessionMap.insert(std::make_pair(userProvidedCode, session)); why doesn't it update invitation code
	AddMessageToCorrectSession(m.connection.id,  "joining lobby: " + code.toString());
	return std::make_pair(true, code);
 }

bool joinSession(const std::string& command, User user){
    std::vector<std::string> params = Command::getCommandArguments(command);

    if (params.size() > 0) {
		Invitation userProvidedCode = Invitation::createInvitationFromStringInput(params.at(0));
		auto userRef = users.getUserRef(user.getUserId());
		if (userRef.has_value()) {
            if (GameSessionManager::joinGameSession(userRef.value(), userProvidedCode)) {
                //AddMessageToCorrectSession(m.connection.id,m.text);
                return true;
            }
        }
	}
	return false;
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
