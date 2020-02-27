#include "GameState.h"

GameState::GameState(GameSpecification::GameSpec& gameSpec) :
    gameSpec(gameSpec),
    gameStarted(false),
    // The following methods are supposed to make copies. I wanted to confirm if they actually do that.
    constantsMap(gameSpec.getConstants()),
    variablesMap(gameSpec.getVariables()),
    perPlayerMap(gameSpec.getPerPlayer()),
    perAudienceMap(gameSpec.getPerAudience())
    {}

void GameState::startGame() {
    gameStarted = true;
}

bool GameState::isGameStarted() const {
    return gameStarted;
}