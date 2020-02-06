#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
// #include<bits/stdc++.h>
class GameSession { 
    
public:
    GameSession(int ownerID);

    // Accessors
    size_t getTotalPlayerCount() const;
    Invitation getInvitationCode() const;
    std::string getSessionName() const;
    bool isGameStarted() const;

    // Mutators
    void setCurrentGame(std::string name);
    void setOwner(uintptr_t ownerID);
    void setTotalNumPlayers(int totalPlayers);
    void addUserToSession(uintptr_t userID);
    void removeUserFromSession(uintptr_t userID);
    void removeAllUsersfromSession();
    void setConfigurationSettings(std::string jsonSettings);
    void createInviteCode();
    void startGame();

    // WIP
    // std::list<Player> getPlayers();  // TODO: Link with the User class
    // void setPlayerInviteCodes();

private:
    std::list<std::string> _ListSettingVars;
    std::list<std::string> _ListPerAudience;
    std::list<std::string> _ListRules;

    std::list<uintptr_t> _playersIDInSession;

    std::string _currentGame;
    std::string _sessionName;
    std::string _invitationCode;
    std::string _JSONSetting;

    int _gameID;
    int _totalNumPlayers;

    bool _isGameStarted;

    uintptr_t _ownerID;

    // WIP
    // std::list<Player> _playersList;  // TODO: Link with the User class
};

#endif