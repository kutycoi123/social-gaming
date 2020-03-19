#include "Parallelfor.h"

using GameSpecification::Parallelfor;
using json = nlohmann::json;

Parallelfor::Parallelfor() : BaseRule(RuleType::ParallelforType) {}

Parallelfor::Parallelfor(const json &ruleJson) : BaseRule(RuleType::ParallelforType){
    parseRule(ruleJson);
}

std::vector<std::string> Parallelfor::getList() const{
    return list;
}

std::string Parallelfor::getElement() const{
    return element;
}

void Parallelfor::process(GameState& gameState){
	//TODO: Add code to process Parallelfor
}

void Parallelfor::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}