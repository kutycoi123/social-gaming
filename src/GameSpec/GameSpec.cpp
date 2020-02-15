#include "GameSpec.h"
#include <fstream>

using GameSpecification::GameSpec;

	std::vector<std::shared_ptr<BaseRule>> GameSpec::getRules() const{
		return _rules;
	}
	std::string GameSpec::getSpecFilePath() const{
		return _specFilePath;
	}
	
	void GameSpec::addRule(std::shared_ptr<BaseRule> rule){
		_rules.push_back(rule);
	}
	
	void GameSpec::setSpecFilePath(const std::string& path){
		_specFilePath = path;
	}
	
	void GameSpec::readSpec(){
	    if(_specFilePath.empty())
	        return;
	    std::ifstream specFile(_specFilePath, std::ifstream::in);
	
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
	
	void GameSpec::addConfig(const GameGeneralConfig& config){
		_config = config;	
	}
