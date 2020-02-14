#include "Server.h"
#include <nlohmann/json.hpp>

#include "GameSessionManager.h"
#include "User.h"
#include "UserList.h"
#include "ProcessCommand.h"
#include <unordered_map> 
#include <atomic>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <thread>
#include <vector>

struct GlobalMessage{
	std::string message;
	//something to specifiy private message, broadcast to specifiv session, broadcast globally (all sessions)
	//maybe user id?, session id?
};

static std::atomic<bool> exit_thread_flag{false};
static const std::string SERVER_CONFIGURATION_FILE_LOCATION = "config/ServerProperties.json";


//std::unordered_map<UserId, Invitation> UserIdTOInvite;
static std::vector<std::string> strVector ;
static std::vector<std::string> splitCommand(std::string s);
const int FIRST_COMMAND = 0;
const int SECOND_COMMAND = 1;
static UserList usersInMainLobby;
 
static GlobalMessage globalMessage = {""};

std::list<GameSession> GameSessionsList;



//main thread
static void OnDisconnect(networking::Connection);
static void OnConnect(networking::Connection);

//these two should definitlly be changed, iirc Hunar is working on them
static std::string getConfigurationFilePath(int, char* []);
static void checkValidConfigurationFile(const nlohmann::json&);

//message thread
static void handleMessages(networking::Server&);
static std::deque<networking::Message> gameServerUpdate(networking::Server&, const std::deque<networking::Message>&);
std::deque<networking::Message> SendMessageToSession();
static std::deque<networking::Message> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming);

void AddMessageToCorrectSession(uintptr_t connectionID, std::string message);
//player authentication. 
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
	//string to short conversion check
	if(port.get<unsigned short>() != port.get<std::intmax_t>()){
		std::cout << "Port out of range\n";
	    std::exit(-1);
	}

	std::string htmlpath = configurationFile.at("HTML Location");
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
		

		//auto outgoing = gameServerUpdate(server, incoming);
		//server.send(outgoing);



		processMessages(server,incoming);

		auto outgoing = SendMessageToSession();
		server.send(outgoing);
		//probably want to replace this with something else
		if (errorWhileUpdating) {
			break;
		}

		sleep(1);
  	}

	return;
}

 
std::deque<networking::Message> SendMessageToSession() {
	std::deque<networking::Message> commandResult;
	GameSessionManager::_invitationToGameSessionMap;

	for ( auto it = GameSessionManager::_invitationToGameSessionMap.begin(); it != GameSessionManager::_invitationToGameSessionMap.end(); it++ ) {

		for ( auto userIterator = it->second.getUsersInSession().begin(); userIterator != it->second.getUsersInSession().end(); userIterator++) {
			
			uintptr_t id = userIterator->first.getId();

			std::queue messages = it->second.getMessages();

			int total =  messages.size();
			 for( int i = 0; i < total;  i++) {

				 	commandResult.push_back(networking::Message{id, messages.front()});
			 }
			
		}
		it->second.clearMessages();

	}
 
	return commandResult;
}
	 
 //paramters connection Id message
 void AddMessageToCorrectSession(uintptr_t connectionID, std::string message) {

	 auto iter =  GameSessionManager::userToInviteCode.find(connectionID);

			 	if(iter != GameSessionManager::userToInviteCode.end()) {
					 	std::cout<<"found invitation"<<"\n";

					 	auto it = GameSessionManager::_invitationToGameSessionMap.find(iter->second);
						
						 
						if(it == GameSessionManager::_invitationToGameSessionMap.end()) {
								std::cout<<"can't find session of user"<<"\n";
						}
						 if(it != GameSessionManager::_invitationToGameSessionMap.end()) {
							 	std::cout<<"added message to session queue";
							 	it->second.addMessages(message);
						 }

				 } 
 }
	
	//usersInMainLobby.begin
	//commandResult.push_back(networking::Message{message.connection, message.text});


static std::deque<networking::Message> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::deque<networking::Message> commandResult;

	for (networking::Message message : incoming) {

		// TODO Mzegar: Use profs iteration when refactor happens
		// Figure out somewhere else to put this
		std::string text = message.text;	

		ProcessCommand::CommandType serverCommand;

		strVector = splitCommand(text);
		
		
		//where to process user Json here?

		serverCommand = ProcessCommand::evaluateCommand(strVector[FIRST_COMMAND]);
		
		if (message.text.find("Configurations") != std::string::npos) {
			// call game engine
			try { nlohmann::json gameConfig = nlohmann::json::parse(message.text);
			} catch( nlohmann::json gameConfig ) {
				std::cout<< "incorrect json";
			}
		}

		if (message.text.find("set Owner") != std::string::npos) {
			// call game engine
			try { nlohmann::json gameConfig = nlohmann::json::parse(message.text);
			} catch( nlohmann::json gameConfig ) {
				std::cout<< "incorrect json";
			}
		}



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
				//print out those string games.
				//find gameSession based on code, push back message to queue

				 
				
				
		 
				AddMessageToCorrectSession(message.connection.id, "start game\n");
				std::cout << "start game\n";
				break;
			}
			case ProcessCommand::CommandType::CREATE_LOBBY:
			{

			 
				UserId id(message.connection.id);
				User owner(id.getId());
				GameSession initSession = GameSessionManager::createGameSession(owner);

			
				Invitation code = initSession.getInvitationCode();
			 
				GameSessionManager::userToInviteCode.insert(std::make_pair(message.connection.id, code));

				AddMessageToCorrectSession(message.connection.id, "Here is the invitational code for your lobby:" + code.toString());
				AddMessageToCorrectSession(message.connection.id, "creating lobby\n");


				//globalMessage.message.append("Creating lobby: \n");
				std::cout << "creating lobby " << '\n';
				//globalMessage.message.append(" Here is the invitational code for your lobby:" + code.toString());


		 

				break;
			}


			case ProcessCommand::CommandType::JOIN_LOBBY:
			{
				UserId id(message.connection.id);
				User name(id.getId());
				Invitation userProvidedCode = Invitation::createInvitationFromStringInput(strVector[SECOND_COMMAND]);


		
				GameSessionManager::joinGameSession(name, userProvidedCode);
				//TODO if not found already. 
				GameSessionManager::userToInviteCode.insert(std::make_pair(message.connection.id,userProvidedCode ));
				AddMessageToCorrectSession(message.connection.id,  "joining lobby: " + userProvidedCode.toString());
			 	
				//globalMessage.message.append("joining lobby: " + userProvidedCode.toString());
				std::cout << "joining lobby: " << userProvidedCode.toString() << "\n";
				break;

			 
			}
			case ProcessCommand::CommandType::USERNAME:
			{
				std::cout << "user name";

			break;
			}
			case ProcessCommand::CommandType::NULL_COMMAND:
			{
				std::cout << "Error, Invalid user command" << '\n';
			break;
			}

			//for example something 
			//game[connection].message = blahblahblah

			//dummy code, remove later
			//push message into Sessions. 
			//if session exists push it into it. 
			//and the message id into it. Pair message, Id,, 
			//
			

		}
		//UserConnection  to Invitation. 
		//GameSession foundSession = GameSessionManager::findGameSession(Invitation());
		//
		//if message[list] is inside the table. 
		//push to that Sessionqueue. 


		commandResult.push_back(networking::Message{message.connection, message.text});
	}

	return commandResult;
}

static std::deque<networking::Message> getGlobalMessages(){
	std::deque<networking::Message> result {};
	
	if(globalMessage.message != ""){

		for(auto& entry : usersInMainLobby){
			User user = entry.second;
			result.push_back({networking::Connection{user.getUserId()}, globalMessage.message});
		}

		globalMessage.message = "";
	}

	return result;
}

std::vector<std::string> splitCommand(std::string s){
    
    std::istringstream iss(s);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
    return results;

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
