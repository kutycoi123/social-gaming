#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "Player.h"
#include<bits/stdc++.h> 
class GameSession { 
    
public:
    GameSession(int ownerID);
    Invitation getInvitationCode() const;
    std::string getSessionName() const;
    void setCurrentGame(std::string name);
    void addUserToSession(uintptr_t userID);
    void removeUserFromSession(uintptr_t userID);
    void removeAllUsersfromSession();
    size_t totalPlayerCount();
    int sessionConfigureSettings(std::string jsonSettings);
    void createInviteCode();
    void setOwner(uintptr_t ownerID);
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
    std::list<uintptr_t> _playersIDInSession;
    std::list<Player> _playersList;

    std::string _sessionName;
    std::string _invitationCode;
    int _gameID;
    int _totalNumPlayers;
    uintptr_t _ownerID;
    std::string _JSONSetting;

};

#endif