#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameSpec.h"

class Game {
public:
    Game(GameSpecification::GameSpec spec, GameState state);
    bool isGameStarted() const;
    void startGame(const std::list<std::weak_ptr<User>>& users);
    void endGame();
    void addMessages(const std::string &message) noexcept;
    std::list<std::pair<UserId, std::string>> updateAndGetAllMessages() noexcept;


private:
    void clearMessages() noexcept;
    std::list<std::pair<UserId, std::string>> getGameMessages() noexcept;

    GameSpecification::GameSpec gameSpec;
    GameState gameState;
    std::list<std::weak_ptr<User>> gameSessionUsers;
    std::list<std::string> messages;
};

#endif //GAME_H
