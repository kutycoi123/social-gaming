#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "UserManager.h"
#include "Invitation.h"
#include "GameParser.h"
#include <list>

class GameSession {
    struct UserList{
        std::list<std::weak_ptr<User>> users;
    };

    public:
        explicit GameSession(std::weak_ptr<User>&, const std::string&);

        bool operator==(const GameSession& gameSession ) const {
            return invitationCode == gameSession.invitationCode;
        }

        void setGame(const std::string&);
        Invitation getInvitationCode() const;
        bool isGameStarted() const;
        void startGame();
        void endGame();

        bool isOwner(const UserId& user) const;

        void addMessages(const std::string &message) noexcept;
        void addMessagesToGame(const std::string &message) noexcept;

        std::list<std::pair<UserId, std::string>> updateAndGetAllMessages() noexcept;

        void addPlayer(const std::weak_ptr<User>& player) noexcept;
        void removePlayer(const std::weak_ptr<User>& player) noexcept;
        
    private:
        std::list<std::string> messages;
        Invitation invitationCode;
        std::unique_ptr<Game> game;
        std::weak_ptr<User>& owner;
        GameSession::UserList playerList;

        void clearMessages() noexcept;
        std::list<std::pair<UserId, std::string>> getLobbyAndGameMessages() noexcept;
};

#endif