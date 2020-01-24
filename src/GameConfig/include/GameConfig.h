//GameConfig.h
#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <string>
#include <vector>



class GameConfig{
public:
	GameConfig();
	GameConfig(const std::string&);
	std::vector<Rule> GetRules() const;
	std::vector<State> GetStates() const;
	std::getConfigFilePath GetConfigFilePath() const;	
	void AddRule(Rule);
	void AddState(State);
	void SetConfigFilePath(const std::string&);
private:
	std::vector<Rule> _rules; 
	std::string _configFilePath;
	
};




#endif





