#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameSpec.h"

class Game {
public:
    Game(GameSpecification::GameSpec spec, GameState state);
    bool isGameStarted() const;
    void startGame();
private:
    GameSpecification::GameSpec gameSpec;
    GameState gameState;
};

#endif //GAME_H
