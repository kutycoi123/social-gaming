#include "GameGeneralConfig.h"

using GameSpecification::GameGeneralConfig;
using GameSpecification::PlayerCount;
using GameSpecification::SpecValue;
using Setup = std::unordered_map<std::string, SpecValue>;

GameGeneralConfig::GameGeneralConfig()
    : name(""),
      playerCount({0, 0}), 
      audience(false),
      setup({}){
}

GameGeneralConfig::GameGeneralConfig(const std::string& name)
    : GameGeneralConfig() {
    this->name = name;
}

inline std::string GameGeneralConfig::getName() const{
    return name;
}

inline PlayerCount GameGeneralConfig::getPlayerCount() const{
    return playerCount;
}

inline bool GameGeneralConfig::hasAudience() const{
    return audience;
}

inline Setup GameGeneralConfig::getSetup() const{
    return setup;
}

void GameGeneralConfig::setName(const std::string& name){
    this->name = name;
}

void GameGeneralConfig::setPlayerCount(const PlayerCount& playerCount){
    this->playerCount = playerCount;
}

void GameGeneralConfig::setAudience(bool audience){
    this->audience = audience;
}

void GameGeneralConfig::setSetup(const Setup& setup){
    this->setup = setup;
}





