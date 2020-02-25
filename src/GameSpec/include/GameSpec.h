//GameSpec.h
#ifndef GAMESPEC_H
#define GAMESPEC_H

#include <string>
#include <vector>
#include <unordered_map>
#include <boost/variant.hpp>
#include <nlohmann/json.hpp>
#include "AbstractSpec.h"
#include "BaseRule.h"
#include "GameGeneralConfig.h"
#include <memory>

using GameSpecification::AbstractSpec;
using GameSpecification::BaseRule;
using GameSpecification::GameGeneralConfig;
namespace GameSpecification{
	class GameSpec : public AbstractSpec{
		public:
		    GameSpec() : specFilePath(""){}
		    GameSpec(const std::string& path) : specFilePath(path) {} 

		    std::vector<std::shared_ptr<BaseRule>> getRules() const;
		    std::string getSpecFilePath() const;	
		    void addRule(std::shared_ptr<BaseRule>);
		    void setSpecFilePath(const std::string&);
		    void readSpec() override; 
		    void parseGameSpec(const nlohmann::json&); 
		    void addConstantSpec(const std::string&, const SpecValue& );
		    void addVariableSpec(const std::string&, const SpecValue& );
		    void addPerPlayerSpec(const std::string&, const SpecValue& );
		    void addPerAudienceSpec(const std::string&, const SpecValue& );
			void addConfig(const GameGeneralConfig& );
		private:
		    std::vector<std::shared_ptr<BaseRule>> rules; 
		    std::string specFilePath;
		    std::unordered_map<std::string, SpecValue> constants;
		    std::unordered_map<std::string, SpecValue> variables;
		    std::unordered_map<std::string, SpecValue> perPlayer;
		    std::unordered_map<std::string, SpecValue> perAudience;  
			GameGeneralConfig config;	
			
	};
	
}
#endif





