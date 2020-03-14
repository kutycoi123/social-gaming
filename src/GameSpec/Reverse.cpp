#include "Reverse.h"

using GameSpecification::Reverse;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Reverse::Reverse() : BaseRule(RuleType::ReverseType), list(""){}

Reverse::Reverse(const std::string& list) : BaseRule(RuleType::ReverseType), list(list) {}

std::string Reverse::getList() const{
    return list;
}

void Reverse::process(GameState& gameState) {
	//TODO: Add code to process reverse rule
}

void Reverse::parseRule(const json& ruleJson){
    try{
        list = ruleJson.at("list").get<std::string>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}