#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "../../invitation/include/Invitation.h"
#include "../../player/include/Player.h"
#include<bits/stdc++.h> 
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

    std::string _sessionName;
    std::string _invitationCode;
    int _gameID;
    int _ownerID;
    std::string _JSONSetting;
    int _totalNumPlayers;

};

#endif