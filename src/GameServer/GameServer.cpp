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

		UserId id(message.connection.id);
        std::optional<std::weak_ptr<User>> user = users->getUserRef(id);
        if (!user.has_value()) continue; // Unlikely to fail, but avoid processing commands from invalid connections.

		auto commandType = GameServerConfiguration::getCommandTypeFromString(*serverConfiguration, message.text);
        std::vector<std::string> commandParams = GameServerConfiguration::getCommandArgumentsFromString(message.text);
		
		switch (commandType)
		{
			case GameServerConfiguration::CommandType::DISCONNECT:
				{
				    // TODO: Disallow users from disconnecting during games
				    // Alongside handling disconnects during games (as per requirements)
					server.disconnect(message.connection);
				}
			break;
			case GameServerConfiguration::CommandType::SHUTDOWN:
				{
                    if (!commandParams.empty()) {
                        Invitation userProvidedCode = Invitation::createInvitationFromStringInput(commandParams.at(0));
                        if (sessionList.endGameInGameSession(user.value(), userProvidedCode)) {
                            message.text.append("\n Ending Game.");
                        }
                        else
                        {
                            message.text.append("\n Unable to end Game. Are you the owner of the lobby?");
                        }
                    }

                    commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});
				}
			break;
			case GameServerConfiguration::CommandType::START_GAME:
				{
                    if (!commandParams.empty()) {
                        Invitation userProvidedCode = Invitation::createInvitationFromStringInput(commandParams.at(0));
                        if (sessionList.startGameInGameSession(user.value(), userProvidedCode)) {
                            message.text.append("\n Starting Game.");
                        }
                        else
                        {
                            message.text.append("\n Unable to start Game. Are you the owner of the lobby?");
                        }
                    }

                    commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});
                }
			break;
			case GameServerConfiguration::CommandType::CREATE_SESSION:
				{
                    auto createdSessionInvitation = sessionList.commenceGameSession(user.value());
                    message.text.append("\n Created Lobby with Invitation code: ");
                    message.text.append(createdSessionInvitation.toString());

					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
			case GameServerConfiguration::CommandType::JOIN_SESSION:
				{
                    if (!commandParams.empty()) {
                        Invitation userProvidedCode = Invitation::createInvitationFromStringInput(commandParams.at(0));
                        if (sessionList.joinGameSession(user.value(), userProvidedCode)) {
                            message.text.append("\n Joining Lobby.");
                        }
                        else
                        {
                            message.text.append("\n Unable to join Lobby.");
                        }
                    }

					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
		    case GameServerConfiguration::CommandType::LEAVE_SESSION:
                {
                    if (!commandParams.empty()) {
                        Invitation userProvidedCode = Invitation::createInvitationFromStringInput(commandParams.at(0));
                        if (sessionList.leaveGameSession(user.value(), userProvidedCode)) {
                            message.text.append("\n Leaving Lobby.");
                        }
                        else
                        {
                            message.text.append("\n Unable to leave Lobby. Have you joined one yet?");
                        }
                    }

                    commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});
                }
            break;
			case GameServerConfiguration::CommandType::USERNAME:
				{
					if (!commandParams.empty()) {
					    auto name = commandParams.at(0);
						user.value().lock()->setUserName(UserName(name));
                        message.text.append("\n Changing name to: " + name);
					}

					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
			case GameServerConfiguration::CommandType::HELP:
				{
					message.text.append("\n List of user commands: \n");
					message.text.append(GameServerConfiguration::getAllCommandDescriptions(*serverConfiguration));
					
					commandResult.push_back(networking::Message{message.connection, message.text.insert(0, user.value().lock()->getUserNameValue() + ": ")});    
				}
			break;
			case GameServerConfiguration::CommandType::NULL_COMMAND:
				{
					if (sessionList.isUserInSession(user.value())){
					    sessionList.addMessages(std::list<Message>{Message{*(user.value().lock()), message.text}});
					}
					else
                    {
						std::cout << "Unrecognized command from User not in session. \n";
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
	
	if(!globalMessage.message.empty()){

		for(auto& entry : *users){
			User user = *(entry.second);
			result.push_back({networking::Connection{user.getUserIdValue()}, globalMessage.message});
		}

		globalMessage.message = "";
	}

	return result;
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