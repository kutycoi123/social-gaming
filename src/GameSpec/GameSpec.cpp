#include "include/GameSpec.h"
#include <fstream>

GameSpec::GameSpec() : _rules(0), _specFilePath(""){
}

GameSpec::GameSpec(const std::string& path) : _specFilePath(path), _rules(0){
}

inline std::vector<Rule> GameSpec::getRules() const{
	return _rules;
}

inline std::string GameSpec::getpecFilePath() const{
	return _specFilePath;
}

void GameSpec::addRule(Rule rule){
	_rules.push_back(rule);
}

void GameSpec::setSpecFilePath(const std::string& path){
	_specFilePath = path;
}

void GameSpec::readSpec(){
    if(_specFilePath.empty())
        return;
    std::ifstream specFile(_specFilePath, std::ifstream::in);

    nlohmann::json gameSpecJson = nlohmann::json::parse(specFile);
    try{
        parseGameSpec(gameSpecJson);
    }catch (int n){
        std::cout << "Parsing error occured\n";
    }

}

void GameSpec::parseGameSpec(const nlohmann::json& json){
    //TODO: add parsing code here
}

void GameSpec::addConstantSpec(const std::string& name, const SpecValue& val){
    _constants[name] = val;
}

void GameSpec::addVariableSpec(const std::string& name, const SpecValue& val){
    _variables[name] = val;
}

void GameSpec::addPerPlayerSpec(const std::string& name, const SpecValue& val){
    _perPlayer[name] = val;
}

void GameSpec::addPerAudienceSpec(const std::string& name, const SpecValue& val){
    _perAudience[name] = val;
}


