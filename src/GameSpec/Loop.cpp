#include "Loop.h"

using GameSpecification::ControlStructRule;
using GameSpecification::Loop;
using json = nlohmann::json;

Loop::Loop() : BaseRule(RuleType::LoopType){}

Loop::Loop(const std::string& loopType, const std::string& failCondition) 
    : BaseRule(RuleType::LoopType), loopType(loopType), failCondition(failCondition){}

std::string Loop::getLoopType() const{
    return loopType;
}

std::string Loop::getFailCondition() const{
    return failCondition;
}

void Loop::process(GameState& gameState){
	//TODO: add code to process loop rule
}

void Loop::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}