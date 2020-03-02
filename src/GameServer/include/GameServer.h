#ifndef GAMESERVER_H
#define GAMESERVER_H

#include "Server.h"
#include "GameSessionList.h"
#include "GameServerConfiguration.h"
#include "list"

struct GlobalMessage{
	std::string message;
	//something to specifiy private message, broadcast to specific session, broadcast globally (all sessions)
	//maybe user id?, session id?
};

class GameServer{
public:
    GameServer(std::unique_ptr<networking::Server>&, std::unique_ptr<GameServerConfiguration>&, std::unique_ptr<UserManager>&);
    void tick();
    void setGlobalMessage(const GlobalMessage& messages) noexcept;
    void addUser(const networking::Connection&) noexcept;
    void removeUser(const networking::Connection&) noexcept;

private:
    std::unique_ptr<networking::Server> server;
    std::unique_ptr<GameServerConfiguration> serverConfiguration;
    std::unique_ptr<UserManager> users;
    
    GlobalMessage globalMessage;
    GameSessionList sessionList;

    std::deque<networking::Message> gameServerUpdate(networking::Server&, const std::deque<networking::Message>&);
    std::deque<networking::Message> SendMessageToSession();
    std::deque<networking::Message> processMessages(networking::Server& server, const std::deque<networking::Message>& incoming);

    // Helper methods
    void AddMessageToCorrectSession(const uintptr_t, const std::string&);
    std::deque<networking::Message> getGlobalMessages();

};

#endif