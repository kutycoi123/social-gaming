#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"

class GameSession { 
    
public:
    GameSession(int ownerID);
    Invitation getInvitationCode() const;
    std::string getSessionName() const;
    void setCurrentGame(std::string name);
    void addUserToSession(int userID);
    void removeUserFromSession(int userID);
    void removeAllUsersfromSession();
    size_t totalPlayerCount();
    int sessionConfigureSettings(std::string jsonSettings);

private:
    std::string _currentGame;
    std::list<int> _playersInSession;
    std::string _sessionName;
    Invitation _invitationCode;
    int _gameID;
    int _ownerID;
    std::string _JSONSetting;

};

#endif