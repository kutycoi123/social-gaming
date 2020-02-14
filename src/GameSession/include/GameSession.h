#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "Game.h"
#include "User.h"
#include "UserList.h"

class GameSession { 
    
public:
    GameSession(User& owner);
    Invitation getInvitationCode() const;
    size_t getTotalPlayerCount() const noexcept;
    std::string getSessionName() const;
    bool isGameStarted() const;

    void setTotalNumPlayers(int totalPlayers);
    void addUserToSession(User& user);
    void removeUserFromSession(User& user);

    void setConfigurationSettings(std::string jsonSettings);
    void createInviteCode();
    void startGame();

    UserList getUsersInSession();

    bool operator==(const GameSession& gameSession ) const {
        return _invitationCode == gameSession._invitationCode;
    }

    // WIP
    // std::list<Player> getPlayers();  // TODO: Link with the User class
    // void setPlayerInviteCodes();

private:
    // Game game;

    std::list<std::string> _ListSettingVars;
    std::list<std::string> _ListPerAudience;
    std::list<std::string> _ListRules;
    std::string _currentGame;
    UserList _usersInSession;

    std::string _sessionName;
    std::string _JSONSetting;

    const Invitation _invitationCode;

    int _gameID;
    int _totalNumPlayers;

    bool _isGameStarted;
    User& _owner;

    uintptr_t _ownerID;

    // WIP
    // std::list<Player> _playersList;  // TODO: Link with the User class
};

#endif