#include "ForEach.h"

using GameSpecification::ForEach;
using GameSpecification::SpecValue;
using GameSpecification::ControlStructRule;
using json = nlohmann::json;
ForEach::ForEach() : BaseRule(RuleType::ForEachType), element(""){}

ForEach::ForEach(const SpecValue& list, const std::string& element) : BaseRule(RuleType::ForEachType),
    list(list), element(element){}

SpecValue ForEach::getList() const{
    return list;
}

std::string ForEach::getElement() const{
    return element;
}



void ForEach::process(GameState& gameState){
	//TODO: Add code to process foreach rule
}

void ForEach::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}