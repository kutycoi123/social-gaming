#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "User.h"
#include "UserList.h"

class GameSession { 
    
public:
    GameSession(User& owner);
    Invitation getInvitationCode() const;
    std::string getSessionName() const;
    void setCurrentGame(std::string name);
    void addUserToSession(User& user);
    void removeUserFromSession(User& user);
    void removeAllUsersfromSession();
    size_t totalPlayerCount() const noexcept;
    int sessionConfigureSettings(std::string jsonSettings);

    UserList getUsersInSession();

    bool operator==(const GameSession& gameSession ) const {
        return _invitationCode == gameSession._invitationCode;
    }

private:
 
    std::list<std::string> _ListSettingVars;
    std::list<std::string> _ListPerAudience;
    std::list<std::string> _ListRules;
    std::string _currentGame;
    UserList _usersInSession;

    std::string _sessionName;
    const Invitation _invitationCode;
    int _gameID;
    int _totalNumPlayers;
    User& _owner;
    std::string _JSONSetting;

};

#endif