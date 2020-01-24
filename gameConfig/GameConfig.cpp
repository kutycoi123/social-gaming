#include "GameConfig.h"


GameConfig::GameConfig() : _rules(0), _states(0), _configFilePath(""){
}

GameConfig::GameConfig(const std::string& path) : _configFilePath(path), _rules(0), _states(0){
}

inline std::vector<Rule> GameConfig::GetRules() const{
	return _rules;
}

inline std::string GameConfig::GetConfigFilePath() const{
	return _configFilePath;
}

void GameConfig::AddRule(Rule rule){
	_rules.push_back(rule);
}

void GameConfig::SetConfigFilePath(const std::string& path){
	_configFilePath = path;
}
