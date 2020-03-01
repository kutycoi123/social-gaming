#include "GameServer.h"

GameServer::GameServer(std::unique_ptr<networking::Server>& server, std::unique_ptr<GameServerConfiguration> &configuration, std::unique_ptr<UserList> &users) :
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

void GameServer::addUser(const UserId& id) noexcept{
	users->add(id);
}

void GameServer::removeUser(const UserId& id) noexcept{
	users->remove(id);
}

std::deque<networking::Message> GameServer::processMessages(networking::Server& server, const std::deque<networking::Message>& incoming) {
	std::deque<networking::Message> commandResult;
	
	for (networking::Message message : incoming) {

		std::string text = message.text;

		UserId id(message.connection.id);
        std::optional<User> user = users->getUser(id); //doesn't make sense for user to not be found, additional check later?

		auto commandType = GameServerConfiguration::getCommandTypeFromString(*serverConfiguration, text);

		if(user != std::nullopt && user.value().isUserInGameSession()){
			//not a command means a regular message, send into server for processing
			//may want to use a different idenfier for this such as "if user is currently in session"
			sessionList.addMessages(std::list<Message>{Message{user.value(), message.text}});
		}
		else{
			switch (commandType)
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
						std::cout << "creating lobby\n";

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
						auto name = GameServerConfiguration::getCommandArgumentsFromString(text);
						auto userRef = users->getUserRef(id);
						if (!name.empty() && userRef.has_value()) {
							userRef.value().get().setUserName(UserName(name.at(0)));
						}
					}
				break;
				case GameServerConfiguration::CommandType::HELP:
					{
						message.text.append("\n List of user commands: \n");
						message.text.append(GameServerConfiguration::getAllCommandDescriptions(*serverConfiguration));
					}
				break;
				case GameServerConfiguration::CommandType::NULL_COMMAND:
					{
						std::cout << "Problem command, something went horribly wrong\n";
					}
				default:
					{
						std::cout << "Problem command, something went horribly wrong\n";
					}
				break;
			}

		    commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().getUserNameValue() + ": ")});

		}
		
		


    }

	return commandResult;
}

std::deque<networking::Message> GameServer::getGlobalMessages(){
	std::deque<networking::Message> result {};
	
	if(globalMessage.message != ""){

		for(auto& entry : *users){
			User user = entry.second;
			result.push_back({networking::Connection{user.getUserIdValue()}, globalMessage.message});
		}

		globalMessage.message = "";
	}

	return result;
}

std::pair<bool, Invitation> GameServer::createSession(networking::Message m, User user){
	Invitation code = sessionList.createGameSession(user);
	//TODO: add mapUserIDToInvitation

	//investigate  GameSessionManager::_invitationToGameSessionMap.insert(std::make_pair(userProvidedCode, session)); why doesn't it update invitation code
	//AddMessageToCorrectSession(m.connection.id,  "joining lobby: " + code.toString());
	return std::make_pair(true, code);
 }

bool GameServer::joinSession(const std::string& command, User user){
    std::vector<std::string> params = GameServerConfiguration::getCommandArgumentsFromString(command);

    if (params.size() > 0) {
		Invitation userProvidedCode = Invitation::createInvitationFromStringInput(params.at(0));
		auto userRef = users->getUserRef(user.getUserId());
		if (userRef.has_value()) {
            if (sessionList.joinGameSession(userRef.value(), userProvidedCode)) {
                //AddMessageToCorrectSession(m.connection.id,m.text);
                return true;
            }
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
