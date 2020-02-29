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
	
	void GameSpec::addConstantSpec(const std::string& name, const SpecValue& val){
	    constants[name] = val;
	}
	
	void GameSpec::addVariableSpec(const std::string& name, const SpecValue& val){
	    variables[name] = val;
	}
	
	void GameSpec::addPerPlayerSpec(const std::string& name, const SpecValue& val){
	    perPlayer[name] = val;
	}
	
	void GameSpec::addPerAudienceSpec(const std::string& name, const SpecValue& val){
	    perAudience[name] = val;
	}
	
	void GameSpec::addConfig(const GameGeneralConfig& config){
		this->config = config;	
	}

    const std::unordered_map<std::string, GameSpecification::SpecValue>& GameSpecification::GameSpec::getConstants() const {
        return constants;
    }

    const std::unordered_map<std::string, GameSpecification::SpecValue>& GameSpecification::GameSpec::getVariables() const {
        return variables;
    }

    const std::unordered_map<std::string, GameSpecification::SpecValue>& GameSpecification::GameSpec::getPerPlayer() const {
        return perPlayer;
    }

    const std::unordered_map<std::string, GameSpecification::SpecValue>& GameSpecification::GameSpec::getPerAudience() const {
        return perAudience;
    }
