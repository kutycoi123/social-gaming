#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
<<<<<<< HEAD
#include "Invitation.h"

=======
#include "../../invitation/include/Invitation.h"
#include "../../player/include/Player.h"
#include<bits/stdc++.h> 
>>>>>>> 934dd06a0ce8f58ef9b347462226443bea00c836
class GameSession { 
    
public:
    GameSession(int ownerID);
    Invitation getInvitationCode() const;
    std::string getSessionName() const;
    void setCurrentGame(std::string name);
    void addUserToSession(Player userID);
    void removeUserFromSession(int userID);
    void removeAllUsersfromSession();
    size_t totalPlayerCount();
    int sessionConfigureSettings(std::string jsonSettings);
<<<<<<< HEAD

private:
    std::string _currentGame;
    std::list<int> _playersInSession;
=======
    void createInviteCode();
    void setOwner(int ownerID);
    std::list<Player> GetPlayers();
    void SetPlayerInviteCodes();
    void SetTotalNumPlayers(int totalPlayers);
    void addUserIDToSession(int userID);

    std::list<Player> getPlayers();

private:
 
    std::list<std::string> _ListSettingVars;
    std::list<std::string> _ListPerAudience;
    std::list<std::string> _ListRules;
    std::string _currentGame;
    std::list<int> _playersIDInSession;
    std::list<Player> _playersList;

>>>>>>> 934dd06a0ce8f58ef9b347462226443bea00c836
    std::string _sessionName;
    std::string _invitationCode;
    int _gameID;
    int _ownerID;
    std::string _JSONSetting;

};

#endif