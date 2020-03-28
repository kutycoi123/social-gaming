#include "include/Game.h"

#include <utility>

Game::Game(GameSpecification::GameSpec spec, GameState state) :
    gameSpec{std::move(spec)},
    gameState{std::move(state)},
    messages{},
    isGameStarted(false)
{}

bool Game::isStarted() const {
    return isGameStarted;
}

void Game::startGame(const std::list<std::weak_ptr<User>>& players, const std::list<std::weak_ptr<User>>& audience) {
    playerList.insert(playerList.end(), players.begin(), players.end());
    audienceList.insert(audienceList.end(), audience.begin(), audience.end());
    addMessages(" User has started the game...\n");
    importGameSpecRules();

    // Once the game has started, gameTick will end up being called.
    isGameStarted = true;
}

void Game::endGame() {
    isGameStarted = false;
}

void Game::addMessages(const std::string &message) noexcept{
    messages.push_back(message);
}

std::list<std::string> Game::updateAndGetAllMessages() noexcept{
    auto gameMessages = messages;
    clearMessages();

    return gameMessages;
}

void Game::clearMessages() noexcept {
    messages = {};
}

void Game::gameTick() {
    bool isProgramCounterWithinRange = currentRuleIndex < gameRules.size();
    if (isProgramCounterWithinRange) {
        /*
        bool isCurrentRuleFullyProcessed = processRule(gameRules.at(currentRuleIndex));
        if (isCurrentRuleFullyProcessed) currentRuleIndex += 1;
        */
    } else {
        endGame();
    }
}

void Game::importGameSpecRules() {
    gameRules.clear();
    gameRules = gameSpec.getRules();
}

bool Game::processRule(std::shared_ptr<BaseRule>& rule) {
    /*
    if (rule != nullptr) {
        rule->process(gameState);
        rule = rule->getNextPtr();
        return false;
    }
    */

    return true;
}