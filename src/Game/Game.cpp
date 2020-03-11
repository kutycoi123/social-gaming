#include "include/Game.h"

#include <utility>

Game::Game(GameSpecification::GameSpec spec, GameState state, std::list<std::weak_ptr<User>>& users) :
    gameSpec{std::move(spec)},
    gameState{std::move(state)},
    gameSessionUsers{users},
    messages{}
{}

bool Game::isGameStarted() const {
    return gameState.isGameStarted();
}

void Game::startGame() {
    return gameState.startGame();
}

void Game::endGame() {
    return gameState.endGame();
}

void Game::addMessages(const std::string &message) noexcept{
    messages.push_back(message);
}

std::list<std::pair<UserId, std::string>> Game::updateAndGetAllMessages() noexcept{
    auto gameMessages = getGameMessages();
    clearMessages();

    return gameMessages;
}

void Game::clearMessages() noexcept {
    messages = {};
}

std::list<std::pair<UserId, std::string>> Game::getGameMessages() noexcept{
    std::list<std::pair<UserId, std::string>> result = {};

    for(auto& message : messages){
        for(auto& player : gameSessionUsers){
            result.emplace_back(player.lock()->getUserId(), message);
        }
    }

    return result;
}
