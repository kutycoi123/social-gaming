#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameSpec.h"

class GameState {
public:
    explicit GameState(GameSpecification::GameSpec&);
    bool isGameStarted() const;
    void startGame();
private:
    bool gameStarted;
    std::unordered_map<std::string, GameSpecification::SpecValue> constantsMap;
    std::unordered_map<std::string, GameSpecification::SpecValue> variablesMap;
    std::unordered_map<std::string, GameSpecification::SpecValue> perPlayerMap;
    std::unordered_map<std::string, GameSpecification::SpecValue> perAudienceMap;
    GameSpecification::GameSpec& gameSpec;
};

#endif
