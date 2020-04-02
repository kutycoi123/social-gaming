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
    gameState.startGame(players, audience);
    addMessageToAllSession(" The game has started!");
    importGameSpecRules();

    // Once the game has started, gameTick will end up being called.
    isGameStarted = true;
}

void Game::endGame() {
    isGameStarted = false;
}

void Game::addMessage(const UserId& userId, const std::string &message) noexcept {
    gameState.addMessage(userId, message);
}

std::list<std::pair<UserId, std::string>> Game::updateAndGetAllMessages() noexcept {
    return gameState.updateAndGetAllMessages();
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

void Game::addMessageToAllPlayers(const std::string &message) noexcept {
    gameState.addMessageToAllPlayers(message);
}

void Game::addMessageToAllAudience(const std::string &message) noexcept {
    gameState.addMessageToAllAudience(message);
}

void Game::addMessageToAllSession(const std::string &message) noexcept {
    gameState.addMessageToEntireSession(message);
}
