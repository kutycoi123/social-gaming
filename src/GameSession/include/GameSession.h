#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "Game.h"
#include "User.h"
#include <queue>
class GameSession { 
    
public:
    GameSession(User& owner);
    Invitation getInvitationCode() const;
    size_t getTotalPlayerCount() const noexcept;
    std::string getSessionName() const;
    bool isGameStarted() const;

    void setConfigurationSettings(std::string jsonSettings);
    void createInviteCode();
    void startGame();
    void clearMessages();

    bool operator==(const GameSession& gameSession ) const {
        return _invitationCode == gameSession._invitationCode;
    }

    void addMessages(const std::string &message);

    std::queue<std::string> getMessages();
    bool doesUserOwnGame(const User& user) const;

    // WIP
    // std::list<Player> getPlayers();  // TODO: Link with the User class
    // void setPlayerInviteCodes();

private:
    // Game game;

    std::list<std::string> _ListSettingVars;
    std::list<std::string> _ListPerAudience;
    std::list<std::string> _ListRules;
    std::string _currentGame;

    std::queue<std::string> messages;

    std::string _sessionName;
    std::string _JSONSetting;

    const Invitation _invitationCode;

    int _gameID;

    bool _isGameStarted;
    User& _owner;
};

#endif