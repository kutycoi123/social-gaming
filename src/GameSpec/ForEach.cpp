#include "ForEach.h"

using GameSpecification::ForEach;
//using GameSpecification::SpecValue;
//using GameSpecification::BaseRule;
using json = nlohmann::json;

ForEach::ForEach(const std::list<std::shared_ptr<BaseRule>>& childRules, const SpecValue& list, const std::string& element) : 
	BaseRule(childRules), 
	list(list), 
	element(element) 
	{}

//TODO: Add code to process foreach rule
void ForEach::process(GameState& gameState){}
