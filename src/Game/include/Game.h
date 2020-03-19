#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameSpec.h"
#include <stack>

class Game {
public:
    Game(GameSpecification::GameSpec spec, GameState state);
    bool isGameStarted() const;
    void startGame(const std::list<std::weak_ptr<User>>& users);
    void endGame();
    void addMessages(const std::string &message) noexcept;
    std::list<std::string> updateAndGetAllMessages() noexcept;
    void gameTick();


private:
    void clearMessages() noexcept;

    // Rule Processor Methods
    void importGameSpecRules();
    void processRule(std::shared_ptr<BaseRule>& rule);

    GameSpecification::GameSpec gameSpec;
    GameState gameState;
    std::vector<std::shared_ptr<BaseRule>> gameRules;
    unsigned int currentRuleIndex;
    std::list<std::weak_ptr<User>> gameSessionUsers;
    std::list<std::string> messages;
};

#endif //GAME_H
