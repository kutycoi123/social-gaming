//GameConfig.h
#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <string>
#include <vector>



class GameConfig{
public:
	GameConfig();
	GameConfig(const std::string&);
	std::vector<Rule> getRules() const;
	std::getConfigFilePath getConfigFilePath() const;	
	void addRule(Rule);
	void addState(State);
	void setConfigFilePath(const std::string&);
private:
	std::vector<Rule> _rules; 
	std::string _configFilePath;
	
};




#endif





