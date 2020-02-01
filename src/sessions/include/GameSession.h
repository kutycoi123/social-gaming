#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "../invitation/include/Invitation.h"
#include "../player/include/Player.h"
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
    void createInviteCode()
    std::list<Player> GetPlayers();
    

private:
 
    std::list<string> _ListSettingVars;
    std::list<string> _ListPerAudience;
    std::list<string> _ListRules;
    std::string _currentGame;
    std::list<int> _playersIDInSession;

    std::list<Player> _playersList;

    std::string _sessionName;
    Invitation _invitationCode;
    int _gameID;
    int _ownerID;
    std::string _JSONSetting;
    int _totalNumPlayers;

};

#endif