#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "Game.h"

class GameSession { 
    
public:
    GameSession(int ownerID);

    Invitation getInvitationCode() const;
    size_t getTotalPlayerCount() const noexcept;
    std::string getSessionName() const;
    bool isGameStarted() const;

    void setCurrentGame(std::string name);
    void setTotalNumPlayers(int totalPlayers);
    void addUserToSession(uintptr_t userID);
    void removeUserFromSession(uintptr_t userID);
    void removeAllUsersfromSession();

    void setConfigurationSettings(std::string jsonSettings);
    void createInviteCode();
    void startGame();

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

    std::list<uintptr_t> _playersIDInSession;

    std::string _currentGame;
    std::string _sessionName;
    std::string _JSONSetting;

    const Invitation _invitationCode;

    int _gameID;
    int _totalNumPlayers;

    bool _isGameStarted;

    uintptr_t _ownerID;

    // WIP
    // std::list<Player> _playersList;  // TODO: Link with the User class
};

#endif