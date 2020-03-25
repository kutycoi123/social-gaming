#include "GameState.h"

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

std::optional<std::weak_ptr<const StateValue>> GameState::getConstant(const std::string& key) {
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

std::optional<std::weak_ptr<const StateValue>> GameState::getConstantOrVariable(const std::string &key) {
    auto constantValue = getConstant(key);
    if (constantValue.has_value()){
        return constantValue;
    }
    return getVariable(key);
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

void GameState::addValue(const std::string &key, StateValueBoolean value, const ValueType& valueType) {
    auto valuePtr = std::make_shared<StateValueBoolean>(std::move(value));
    std::pair<std::string, std::shared_ptr<StateValue>> pair = std::make_pair(key, valuePtr);
    insertIntoCorrectMap(valueType, pair);
}

void GameState::addValue(const std::string &key, StateValueNumber value, const ValueType& valueType) {
    auto valuePtr = std::make_shared<StateValueNumber>(std::move(value));
    std::pair<std::string, std::shared_ptr<StateValue>> pair = std::make_pair(key, valuePtr);
    insertIntoCorrectMap(valueType, pair);
}

void GameState::addValue(const std::string &key, StateValueString value, const ValueType& valueType) {
    auto valuePtr = std::make_shared<StateValueString>(std::move(value));
    std::pair<std::string, std::shared_ptr<StateValue>> pair = std::make_pair(key, valuePtr);
    insertIntoCorrectMap(valueType, pair);
}

void GameState::addValue(const std::string &key, StateValueList value, const ValueType& valueType) {
    auto valuePtr = std::make_shared<StateValueList>(std::move(value));
    std::pair<std::string, std::shared_ptr<StateValue>> pair = std::make_pair(key, valuePtr);
    insertIntoCorrectMap(valueType, pair);
}

void GameState::addValue(const std::string &key, StateValueMap value, const ValueType& valueType) {
    auto valuePtr = std::make_shared<StateValueMap>(std::move(value));
    std::pair<std::string, std::shared_ptr<StateValue>> pair = std::make_pair(key, valuePtr);
    insertIntoCorrectMap(valueType, pair);
}

void GameState::insertIntoCorrectMap(const GameState::ValueType &valueType,
                                     std::pair<std::string, std::shared_ptr<StateValue>>& pair) {
    switch (valueType){
        case CONSTANT:
            constantsMap.insert(std::move(pair));
            break;
        case VARIABLE:
            variablesMap.insert(std::move(pair));
            break;
        case PER_PLAYER:
            perPlayerMap.insert(std::move(pair));
            break;
        case PER_AUDIENCE:
            perAudienceMap.insert(std::move(pair));
            break;
    }
}

void GameState::addMessages(const std::string &message) noexcept{
    messages.push_back(message);
}

void GameState::clearMessages() noexcept {
    messages = {};
}

std::list<std::string> GameState::updateAndGetAllMessages() noexcept{
    auto gameMessages = messages;
    clearMessages();

    return gameMessages;
}

void GameState::addConfig(const GameConfig& gameConfig){
    this->gameConfig = gameConfig;
}
