#include "GameSpec.h"
#include <fstream>

using GameSpecification::GameSpec;

	std::vector<std::shared_ptr<BaseRule>> GameSpec::getRules() const{
		return rules;
	}
	std::string GameSpec::getSpecFilePath() const{
		return specFilePath;
	}
	
	void GameSpec::addRule(std::shared_ptr<BaseRule> rule){
		rules.push_back(rule);
	}
	
	void GameSpec::setSpecFilePath(const std::string& path){
		specFilePath = path;
	}
	
	void GameSpec::readSpec(){
	    if(specFilePath.empty())
	        return;
	    std::ifstream specFile(specFilePath, std::ifstream::in);
	
	    try{
	    	nlohmann::json gameSpecJson = nlohmann::json::parse(specFile);
	        parseGameSpec(gameSpecJson);
	    }catch (int n){
	        //std::cout << "Parsing error occured\n";
			//TODO: Handle error
	    }
	
	}
	
	void GameSpec::parseGameSpec(const nlohmann::json& json){
	    //TODO: add parsing code here
	}

