#include "GameState.h"
#include <optional>

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

std::optional<std::weak_ptr<StateValue>> GameState::getConstant(const std::string& key) {
    auto it = constantsMap.find(key);
    return (it != constantsMap.end()) ?
        std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}

std::optional<std::weak_ptr<StateValue>> GameState::getVariable(const std::string& key) {
    auto it = variablesMap.find(key);
    return (it != variablesMap.end()) ?
           std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}

std::optional<std::weak_ptr<StateValue>> GameState::getPerPlayerValue(const std::string& key) {
    auto it = perPlayerMap.find(key);
    return (it != perPlayerMap.end()) ?
        std::make_optional(std::weak_ptr(it->second)) :
        std::nullopt;
}

std::optional<std::weak_ptr<StateValue>> GameState::getPerAudienceValue(const std::string& key) {
    auto it = perAudienceMap.find(key);
    return (it != perAudienceMap.end()) ?
           std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}

void GameState::addConstant(const std::string &key, const StateValue& value) {
    // TODO: Implement this method
}

void GameState::addVariable(const std::string &key, const StateValue& value) {
    // TODO: Implement this method
}

void GameState::addPerPlayer(const std::string &key, const StateValue& value) {
    // TODO: Implement this method
}

void GameState::addPerAudience(const std::string &key, const StateValue& value) {
    // TODO: Implement this method
}

void GameState::addConfig(const GameConfig& gameConfig){
    this->gameConfig = gameConfig;
}