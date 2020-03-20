//GameSpec.h
#ifndef GAMESPEC_H
#define GAMESPEC_H

#include <string>
#include <vector>
#include <unordered_map>
#include <boost/variant.hpp>
#include <nlohmann/json.hpp>
#include "BaseRule.h"
#include <memory>

#include "GameState.h"

using GameSpecification::BaseRule;

namespace GameSpecification{
	class GameSpec{
		public:
		    GameSpec() : specFilePath(""){}
		    explicit GameSpec(const std::string& path) : specFilePath(path) {}
		    std::vector<std::shared_ptr<BaseRule>> getRules() const;
		    std::string getSpecFilePath() const;	
		    void addRule(std::shared_ptr<BaseRule>);
		    void setSpecFilePath(const std::string&);
		    void readSpec(); 
		    void parseGameSpec(const nlohmann::json&); 
		private:
		    std::vector<std::shared_ptr<BaseRule>> rules; 
		    std::string specFilePath;
	};
	
}
#endif





