#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameSpec.h"
#include <stack>

class Game {
public:
    Game(GameSpecification::GameSpec spec, GameState state);
    bool isStarted() const;
    void startGame(const std::list<std::weak_ptr<User>>& players, const std::list<std::weak_ptr<User>>& audience);
    void endGame();
    void addMessages(const std::string &message) noexcept;
    std::list<std::string> updateAndGetAllMessages() noexcept;
    void gameTick();


private:
    // Rule Processor Methods
    void importGameSpecRules();
    bool processRule(std::shared_ptr<BaseRule>& rule);

    GameSpecification::GameSpec gameSpec;
    GameState gameState;
    std::list<std::shared_ptr<BaseRule>> gameRules;
    unsigned int currentRuleIndex;
    std::list<std::weak_ptr<User>> playerList;
    std::list<std::weak_ptr<User>> audienceList;
    std::list<std::string> messages;
    bool isGameStarted;
};

#endif //GAME_H
