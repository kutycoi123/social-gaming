#include "include/GameGeneralConfig.h"

GameGeneralConfig::GameGeneralConfig()
    : _name(""),
      _playerCnt({0, 0}), 
      _audience(false),
      _setup({1}){
}

GameGeneralConfig::GameGeneralConfig(const std::string& name)
    : GameGeneralConfig() {
    _name = name;
}

inline std::string GameGeneralConfig::getName() const{
    return _namel
}

inline PlayerCount GameGeneralConfig::getPlayerCount() const{
    return _playerCnt;
}

inline bool GameGeneralConfig::hasAudience() const{
    return _audience;
}

inline Setup getSetup() const{
    return _setup;
}

void GameGeneralConfig::setName(const std::string& name){
    _name = std::move(name);
}

void GameGeneralConfig::setPlayerCount(const PlayerCount& cnt){
    _playerCnt = cnt;
}

void GameGeneralConfig::setAudience(bool audience){
    _audience = audience;
}

void GameGeneralConfig::setSetup(const Setup& setup){
    _setup = setup;
}





