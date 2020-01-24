#include "GameConfig.h"


GameConfig::GameConfig() : _rules(0), _states(0), _configFilePath(""){
}

GameConfig::GameConfig(const std::string& path) : _configFilePath(path), _rules(0), _states(0){
}

inline std::vector<Rule> GameConfig::getRules() const{
	return _rules;
}

inline std::string GameConfig::getConfigFilePath() const{
	return _configFilePath;
}

void GameConfig::addRule(Rule rule){
	_rules.push_back(rule);
}

void GameConfig::setConfigFilePath(const std::string& path){
	_configFilePath = path;
}
