#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "GameState.h"
#include "User.h"
#include "UserList.h"
#include <queue>
#include <GameSpec.h>

class GameSession {
    
public:
    explicit GameSession(User& owner);
    Invitation getInvitationCode() const;
    size_t getTotalPlayerCount() const noexcept;
    std::string getSessionName() const;
    bool isGameStarted() const;

    void addUserToSession(User& user);
    void removeUserFromSession(User& user);
    void removeAllUsersfromSession();

    void setConfigurationSettings(std::string& jsonSettings);
    void startGame();
    void clearMessages();
    UserList getUsersInSession();

    bool operator==(const GameSession& gameSession ) const {
        return invitationCode == gameSession.invitationCode;
    }

    void addMessages(const std::string &message);

    std::queue<std::string> getMessages();
    bool doesUserOwnGame(const User& user) const;

private:
    std::string currentGame;
    UserList usersInSession;

    std::queue<std::string> messages;

    std::string sessionName;
    std::string JSONSetting;

    const Invitation invitationCode;

    GameState gameState;
    GameSpecification::GameSpec gameSpec;
    User& owner;

    // WIP
    // std::list<Player> _playersList;  // TODO: Link with the User class
};

#endif