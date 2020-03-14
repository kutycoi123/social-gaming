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
    return gameState.startGame();
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

void Game::executeCurrentRule() {
    auto rules = programCounter.top();
    for (auto& rule : rules) {
        rule.lock()->process(gameState);
    }

    programCounter.pop();
}

void Game::getNextRule() {

}

void Game::importAllRules() {

}