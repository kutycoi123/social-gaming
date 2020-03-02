#include "GameState.h"
#include <optional>
#include <boost/variant.hpp>

GameState::GameState(GameSpecification::GameSpec& gameSpec) :
    gameSpec(gameSpec),
    gameStarted(false),
    constantsMap(gameSpec.getConstants()),
    variablesMap(gameSpec.getVariables()),
    perPlayerMap(gameSpec.getPerPlayer()),
    perAudienceMap(gameSpec.getPerAudience())
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

// TODO: Find a better way to handle wrapping and unwrapping of boost::variants
void GameState::setVariable(const std::string& key, boost::variant<std::string, int, bool, double> newValue) {
    auto it = variablesMap.find(key);
    if (it != variablesMap.end()) {
        auto retrievedValue = boost::get<int>(newValue);
        it->second.value = retrievedValue;
    }
}

std::optional<std::reference_wrapper<GameSpecification::SpecValue>> GameState::getConstant(const std::string& key) {
    auto it = constantsMap.find(key);
    return (it != constantsMap.end()) ?
        std::optional<std::reference_wrapper<GameSpecification::SpecValue>>{it->second} :
        std::nullopt;
}

std::optional<std::reference_wrapper<GameSpecification::SpecValue>> GameState::getVariables(const std::string& key) {
    auto it = variablesMap.find(key);
    return (it != variablesMap.end()) ?
           std::optional<std::reference_wrapper<GameSpecification::SpecValue>>{it->second} :
           std::nullopt;
}

std::optional<std::reference_wrapper<GameSpecification::SpecValue>> GameState::getPerPlayerValue(const std::string& key) {
    auto it = perPlayerMap.find(key);
    return (it != perPlayerMap.end()) ?
           std::optional<std::reference_wrapper<GameSpecification::SpecValue>>{it->second} :
           std::nullopt;
}

std::optional<std::reference_wrapper<GameSpecification::SpecValue>> GameState::getPerAudienceValue(const std::string& key) {
    auto it = perAudienceMap.find(key);
    return (it != perAudienceMap.end()) ?
           std::optional<std::reference_wrapper<GameSpecification::SpecValue>>{it->second} :
           std::nullopt;
}
