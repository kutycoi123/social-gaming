#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameSpec.h"

// Forward declaration required due to circular reference between GameSpec and GameState
// https://stackoverflow.com/questions/2133250/x-does-not-name-a-type-error-in-c/2133260
// https://stackoverflow.com/questions/19001700/how-to-forward-declare-a-class-which-is-in-a-namespace
namespace GameSpecification {
    class AbstractSpec;
    class GameSpec;
}

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
    GameSpecification::GameSpec& gameSpec;
    bool gameStarted;
    std::unordered_map<std::string, GameSpecification::SpecValue> constantsMap;
    std::unordered_map<std::string, GameSpecification::SpecValue> variablesMap;
    // TODO: Will change perPlayer/perAudience impl to be different from constantsMap/variablesMap
    std::unordered_map<std::string, GameSpecification::SpecValue> perPlayerMap;
    std::unordered_map<std::string, GameSpecification::SpecValue> perAudienceMap;
};

#endif
