#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "UserManager.h"
#include "Invitation.h"
#include "Game.h"
#include <list>

class GameSession {
    struct UserList{
        std::list<std::weak_ptr<User>> users;
    };

    public:
        explicit GameSession(std::weak_ptr<User>& owner);

        bool operator==(const GameSession& gameSession ) const {
            return invitationCode == gameSession.invitationCode;
        }

        Invitation getInvitationCode() const;
        bool isGameStarted() const;
        void startGame();

        bool isOwner(const UserId& user) const;

        void addMessages(const std::string &message) noexcept;

        std::list<std::pair<UserId, std::string>> updateAndGetAllMessages() noexcept;

        void addPlayer(const std::weak_ptr<User>& player) noexcept;
        void removePlayer(const std::weak_ptr<User>& player) noexcept;
        
    private:
        std::list<std::string> messages;
        Invitation invitationCode;
        Game game;
        std::weak_ptr<User>& owner;
        GameSession::UserList playerList;

        void clearMessages() noexcept;
        std::list<std::pair<UserId, std::string>> getLobbyMessages() noexcept;
};

#endif