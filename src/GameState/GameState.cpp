#include "include/GameState.h"

GameState::GameState() : gameStarted(false) {

}

void GameState::startGame() {
    gameStarted = true;
}

bool GameState::isGameStarted() const {
    return gameStarted;
}