#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <vector>
#include "../../invitation/include/Invitation.h"

// for 1 session the info for it to work. 
// infor on each session of a game, 
//

class GameSession { 
    
public:
    GameSession();
    std::string getInvitationCode() const;
    void setOwner(int ownerID);
    void setCurrentGame(std::string name);
    void addUserToSession(int userID);
    void removeAllUserfromSession();
    int sessionConfigureSettings(std::string jsonSettings);

private:

    std::vector<int> _playersInSession;
    std::string _currentGame;
    Invitation _invitationCode;
    int _sessionID;
    int _gameID;
    int _ownerID;
    std::string _JSONSetting;

};

#endif