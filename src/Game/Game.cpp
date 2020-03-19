#include "include/Game.h"

#include <utility>

Game::Game(GameSpecification::GameSpec spec, GameState state) :
    gameSpec{std::move(spec)},
    gameState{std::move(state)},
    messages{}
{}

bool Game::isGameStarted() const {
    return gameState.isGameStarted();
}

void Game::startGame(const std::list<std::weak_ptr<User>>& users) {
    gameSessionUsers.insert(gameSessionUsers.end(), users.begin(), users.end());
    addMessages(" User has started the game...\n");
    importGameSpecRules();

    // Once the game as started, gameTick will end up being called with processes the rules.
    gameState.startGame();
}

void Game::endGame() {
    return gameState.endGame();
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
        processRule(gameRules.at(currentRuleIndex));
        currentRuleIndex += 1;
    } else {
        endGame();
    }
}

void Game::importGameSpecRules() {
    gameRules.clear();
    gameRules = gameSpec.getRules();
}

void Game::processRule(std::shared_ptr<BaseRule>& rule) {
    rule->process(gameState);

    rule = rule->getNextPtr();
    if (rule != nullptr) {
        processRule(rule);
    }
}