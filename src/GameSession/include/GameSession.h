#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "Game.h"
#include "User.h"
#include "UserList.h"
#include <queue>
class GameSession { 
    
public:
    GameSession(User& owner);
    Invitation getInvitationCode() const;
    size_t getTotalPlayerCount() const noexcept;
    std::string getSessionName() const;
    bool isGameStarted() const;

    void addUserToSession(User& user);
    void removeUserFromSession(User& user);
    void removeAllUsersfromSession();

    void setConfigurationSettings(std::string jsonSettings);
    void createInviteCode();
    void startGame();
    void clearMessages();
    UserList getUsersInSession();

    bool operator==(const GameSession& gameSession ) const {
        return invitationCode == gameSession.invitationCode;
    }

    void addMessages(const std::string &message);

    std::queue<std::string> getMessages();
    bool doesUserOwnGame(const User& user) const;

    // WIP
    // std::list<Player> getPlayers();  // TODO: Link with the User class
    // void setPlayerInviteCodes();

private:
    // Game game;

    std::list<std::string> listSettingVars;
    std::list<std::string> listPerAudience;
    std::list<std::string> listRules;
    std::string currentGame;
    UserList usersInSession;

    std::queue<std::string> messages;

    std::string sessionName;
    std::string JSONSetting;

    const Invitation invitationCode;

    int gameID;

    bool gameStarted;
    User& owner;

    // WIP
    // std::list<Player> _playersList;  // TODO: Link with the User class
};

#endif