#include "GameState.h"
#include <optional>
#include <boost/variant.hpp>

GameState::GameState() :
    gameStarted(false)
    {}

void GameState::startGame() {
    gameStarted = true;
}

void GameState::endGame() {
    gameStarted = false;
}

bool GameState::isGameStarted() const {
    return gameStarted;
}

std::optional<std::weak_ptr<StateValue::ConstantValue>> GameState::getConstant(const std::string& key) {
    auto it = constantsMap.find(key);
    return (it != constantsMap.end()) ?
        std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}

std::optional<std::weak_ptr<StateValue::VariableValue>> GameState::getVariable(const std::string& key) {
    auto it = variablesMap.find(key);
    return (it != variablesMap.end()) ?
           std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}

std::optional<std::weak_ptr<StateValue::PerPlayerValue>> GameState::getPerPlayerValue(const std::string& key) {
    auto it = perPlayerMap.find(key);
    return (it != perPlayerMap.end()) ?
        std::make_optional(std::weak_ptr(it->second)) :
        std::nullopt;
}

std::optional<std::weak_ptr<StateValue::PerAudienceValue>> GameState::getPerAudienceValue(const std::string& key) {
    auto it = perAudienceMap.find(key);
    return (it != perAudienceMap.end()) ?
           std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}
