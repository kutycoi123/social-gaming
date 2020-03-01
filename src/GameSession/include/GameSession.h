#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "GameState.h"
#include "User.h"
#include <queue>
#include <GameSpec.h>

class GameSession {
    
public:
    explicit GameSession(User& owner);
    Invitation getInvitationCode() const;
    bool isGameStarted() const;
    void startGame();
    void clearMessages();

    bool operator==(const GameSession& gameSession ) const {
        return invitationCode == gameSession.invitationCode;
    }

    void addMessages(const std::string &message);

    std::queue<std::string> getMessages();
    bool doesUserOwnGame(const User& user) const;

private:
    std::queue<std::string> messages;
    Invitation invitationCode;
    GameSpecification::GameSpec gameSpec;
    GameState gameState;
    User& owner;
};

#endif