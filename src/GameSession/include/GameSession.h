#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "GameState.h"
#include "UserList.h"
#include <list>
#include <GameSpec.h>

class GameSession {
    public:
        explicit GameSession(User& owner);

        bool operator==(const GameSession& gameSession ) const {
            return invitationCode == gameSession.invitationCode;
        }

        Invitation getInvitationCode() const;
        bool isGameStarted() const;
        void startGame();

        bool isOwner(const User& user) const;

        void addMessages(const std::string &message) noexcept;

        std::list<std::pair<UserId, std::string>> updateAndGetAllMessages() noexcept;

        void addPlayer(const User& player) noexcept;
        void removePlayer(const User& player) noexcept;

    private:
        std::list<std::string> messages;
        Invitation invitationCode;
        GameSpecification::GameSpec gameSpec;
        GameState gameState;
        User& owner;
        UserList playerList;

        void clearMessages() noexcept;
        std::list<std::pair<UserId, std::string>> getLobbyMessages() noexcept;
};

#endif