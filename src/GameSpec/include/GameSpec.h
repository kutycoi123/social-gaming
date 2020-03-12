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
#include <memory>

#include "GameState.h"

// TODO: Remove when circular dependency between GameState and GameSpec is resolved
namespace GameSpecification {
    class BaseRule;
}

using GameSpecification::AbstractSpec;
using GameSpecification::BaseRule;
namespace GameSpecification{
	class GameSpec : public AbstractSpec{
		public:
		    GameSpec() : specFilePath(""){}
		    explicit GameSpec(const std::string& path) : specFilePath(path) {}
		    std::vector<std::shared_ptr<BaseRule>> getRules() const;
		    std::string getSpecFilePath() const;	
		    void addRule(std::shared_ptr<BaseRule>);
		    void setSpecFilePath(const std::string&);
		    void readSpec() override; 
		    void parseGameSpec(const nlohmann::json&); 
		private:
		    std::vector<std::shared_ptr<BaseRule>> rules; 
		    std::string specFilePath;
	};
	
}
#endif





