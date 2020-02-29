#ifndef GAMESERVER_H
#define GAMESERVER_H

#include "Server.h"
#include "GameSessionManager.h"
#include "GameServerConfiguration.h"
#include "User.h"

struct GlobalMessage{
	std::string message;
	//something to specifiy private message, broadcast to specific session, broadcast globally (all sessions)
	//maybe user id?, session id?
};

class GameServer{
public:
    GameServer(std::unique_ptr<networking::Server>&, std::unique_ptr<GameServerConfiguration>&, std::unique_ptr<UserList>&);
    void tick();
    void setGlobalMessage(const GlobalMessage& messages) noexcept;
    void addUser(const UserId&) noexcept;
    void removeUser(const UserId&) noexcept;

private:
    std::unique_ptr<networking::Server> server;
    std::unique_ptr<GameServerConfiguration> serverConfiguration;
    GlobalMessage globalMessage;
    std::unique_ptr<UserList> users;

    std::deque<networking::Message> gameServerUpdate(networking::Server&, const std::deque<networking::Message>&);
    std::deque<networking::Message> SendMessageToSession();
    std::deque<networking::Message> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming);

    //helper methods
    std::pair<bool, Invitation> createSession(networking::Message, User);
    bool joinSession(const std::string&, User);
    void AddMessageToCorrectSession(const uintptr_t, const std::string&);
    std::deque<networking::Message> getGlobalMessages();

};

#endif