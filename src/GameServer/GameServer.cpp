#include "GameServer.h"

GameServer::GameServer(std::unique_ptr<networking::Server>& server, std::unique_ptr<GameServerConfiguration> &configuration, std::unique_ptr<UserManager> &users) :
	server(std::move(server)),
	serverConfiguration(std::move(configuration)),
	users(std::move(users)),
	sessionList(GameSessionList()) 
	{}	

void GameServer::tick(){
	try {
		server->update();
	} 
	catch (std::exception& e) {
		std::cerr << "Exception from Server update:\n"
					<< " " << e.what() << "\n\n";
		return;
	}

	auto incoming = server->receive();

	auto outgoing = gameServerUpdate(*server, incoming);

	server->send(outgoing);
}

void GameServer::setGlobalMessage(const GlobalMessage& message) noexcept{
	globalMessage = message;
}

void GameServer::addUser(const networking::Connection& connection) noexcept{
	users->createUser(UserId(connection.id));
}

void GameServer::removeUser(const networking::Connection& connection) noexcept{
	users->destroyUser(UserId(connection.id));
}

std::deque<networking::Message> GameServer::processMessages(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::deque<networking::Message> commandResult;
	
	for (networking::Message message : incoming) {

		std::string text = message.text;

		UserId id(message.connection.id);
        std::optional<std::weak_ptr<User>> user = users->getUserRef(id); //doesn't make sense for user to not be found, additional check later?

		auto commandType = GameServerConfiguration::getCommandTypeFromString(*serverConfiguration, text);
		
		switch (commandType)
		{
			case GameServerConfiguration::CommandType::DISCONNECT:
				{
					server.disconnect(message.connection);
					
					message.text.append("\nDisconnected");

					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
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
					std::cout << "start game\n";
					// TODO: swap gamesession's gamestate gamestarted flag
				}
			break;
			case GameServerConfiguration::CommandType::CREATE_SESSION:
				{
					std::cout << "creating lobby\n";

					if(user.has_value()){
						std::pair<bool, Invitation> session = createSession(message, user.value());
						if (!session.first){
							message.text.append("\nError, Could not create lobby!");
						}
						else
						{
							message.text.append("\nCreated Lobby with Invitation code: ");
							message.text.append(session.second.toString());

							std::cout << "Created Lobby " << session.second.toString() << '\n';
						}
					}

					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
			case GameServerConfiguration::CommandType::JOIN_SESSION:
				{
					if(!joinSession(text, user.value())){
						message.text.append("\nError, cannot join lobby!");
					}
					else{
					    std::vector<std::string> params = GameServerConfiguration::getCommandArgumentsFromString(text);

						message.text.append("\nJoined lobby ");
						message.text.append(params.at(0));
					}

					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
			case GameServerConfiguration::CommandType::USERNAME:
				{
					//TODO: add user friendly response

					auto name = GameServerConfiguration::getCommandArgumentsFromString(text);
					auto userRef = users->getUserRef(id);
					if (!name.empty() && userRef.has_value()) {
						userRef.value().lock()->setUserName(UserName(name.at(0)));
					}

					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
			case GameServerConfiguration::CommandType::HELP:
				{
					//TODO: fix printing

					message.text.append("\n List of user commands: \n");
					message.text.append(GameServerConfiguration::getAllCommandDescriptions(*serverConfiguration));
					
					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
			case GameServerConfiguration::CommandType::NULL_COMMAND:
				{
					//if user in session
					if(sessionList.isUserInSession(user.value())){
					sessionList.addMessages(std::list<Message>{Message{*(user.value().lock()), message.text}});
					}
					else {
						std::cout << "unrecognized command from a user that is not in a session\n";
					}		
				}
			break;
			default:
				{
					std::cout << "Problem command, something went horribly wrong\n";
				}
			break;
		}
	}
	
	return commandResult;
}

std::deque<networking::Message> GameServer::getGlobalMessages(){
	std::deque<networking::Message> result {};
	
	if(globalMessage.message != ""){

		for(auto& entry : *users){
			User user = *(entry.second);
			result.push_back({networking::Connection{user.getUserIdValue()}, globalMessage.message});
		}

		globalMessage.message = "";
	}

	return result;
}

std::pair<bool, Invitation> GameServer::createSession(networking::Message m, std::weak_ptr<User>& user){
	Invitation code = sessionList.commenceGameSession(user);
	//TODO: add mapUserIDToInvitation

	//investigate  GameSessionManager::_invitationToGameSessionMap.insert(std::make_pair(userProvidedCode, session)); why doesn't it update invitation code
	//AddMessageToCorrectSession(m.connection.id,  "joining lobby: " + code.toString());
	return std::make_pair(true, code);
 }

bool GameServer::joinSession(const std::string& command, std::weak_ptr<User>& user){
    std::vector<std::string> params = GameServerConfiguration::getCommandArgumentsFromString(command);

    if (params.size() > 0) {
		Invitation userProvidedCode = Invitation::createInvitationFromStringInput(params.at(0));
		if (sessionList.joinGameSession(user, userProvidedCode)) {
			//AddMessageToCorrectSession(m.connection.id,m.text);
			return true;
		}
        
	}
	return false;
}

std::deque<networking::Message> GameServer::gameServerUpdate(networking::Server& server, const std::deque<networking::Message>& incoming) {

	std::deque<networking::Message> allMessages = {};

	std::deque<networking::Message> globalMessages = getGlobalMessages();
	allMessages.insert(allMessages.end(), globalMessages.begin(), globalMessages.end());

	//doesn't really make sense for command messages to be broadcasted to everyone, so only the person creating the command needs to see the server reply
	std::deque<networking::Message> commandMessages = processMessages(server, incoming);
	allMessages.insert(allMessages.end(), commandMessages.begin(), commandMessages.end());

	//TODO: update all games based on game logic (probs in gamesessionmanager)

	std::list<Message> rawSessionMessages = sessionList.updateAndGetAllMessages();
	std::deque<networking::Message> transformedSessionMessages {};

	std::transform(rawSessionMessages.begin(), rawSessionMessages.end(), std::back_inserter(transformedSessionMessages), [](const Message& message){
		return networking::Message{networking::Connection{message.user.getUserId().getId()}, message.payload};
	});

	allMessages.insert(allMessages.end(), transformedSessionMessages.begin(), transformedSessionMessages.end());

	return allMessages;
}
