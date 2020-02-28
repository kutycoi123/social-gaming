#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameSpec.h"

class GameState {
public:
    explicit GameState(GameSpecification::GameSpec&);
    bool isGameStarted() const;
    void startGame();
    std::optional<std::reference_wrapper<GameSpecification::SpecValue>> getConstant(const std::string&);
    std::optional<std::reference_wrapper<GameSpecification::SpecValue>> getVariables(const std::string&);
    std::optional<std::reference_wrapper<GameSpecification::SpecValue>> getPerPlayerValue(const std::string&);
    std::optional<std::reference_wrapper<GameSpecification::SpecValue>> getPerAudienceValue(const std::string&);
private:
    bool gameStarted;
    std::unordered_map<std::string, GameSpecification::SpecValue> constantsMap;
    std::unordered_map<std::string, GameSpecification::SpecValue> variablesMap;
    // Will change perPlayer/perAudience impl to be different from constantsMap/variablesMap
    std::unordered_map<std::string, GameSpecification::SpecValue> perPlayerMap;
    std::unordered_map<std::string, GameSpecification::SpecValue> perAudienceMap;
    GameSpecification::GameSpec& gameSpec;
};

#endif
