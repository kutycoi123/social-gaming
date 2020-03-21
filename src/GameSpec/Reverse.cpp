#include "Reverse.h"
#include "ReverseVisitor.h"
#include <iterator>
#include <algorithm>

using GameSpecification::Reverse;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Reverse::Reverse() : BaseRule(RuleType::ReverseType), list(""){}

Reverse::Reverse(const json &ruleJson) : BaseRule(RuleType::ReverseType){
    parseRule(ruleJson);
}

std::string Reverse::getList() const{
    return list;
}

void Reverse::process(GameState& gameState) {
    auto variables = gameState.getVariable(list);
    if(auto retrievedValue = variables->lock()){
        ReverseVisitor visitor;
        retrievedValue->accept(visitor);
    }
}

void Reverse::parseRule(const json& ruleJson){
    try{
        list = ruleJson.at("list").get<std::string>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}