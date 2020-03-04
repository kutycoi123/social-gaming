#include "include/Game.h"

#include <utility>

Game::Game(GameSpecification::GameSpec spec, GameState state) :
    gameSpec{std::move(spec)},
    gameState{std::move(state)}
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
