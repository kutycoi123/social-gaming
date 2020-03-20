#include "Loop.h"

using GameSpecification::Loop;
using json = nlohmann::json;

Loop::Loop(const std::list<std::shared_ptr<BaseRule>>& childRules, const std::string& loopType, const std::string& failCondition) : 
    BaseRule(childRules), 
    loopType(loopType), 
    failCondition(failCondition)
    {}

void Loop::process(GameState& gameState){
	//TODO: add code to process loop rule
}
