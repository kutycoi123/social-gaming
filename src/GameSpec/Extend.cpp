#include "Extend.h"
#include "ExtendVisitor.h"

using GameSpecification::BaseRule;
using GameSpecification::Extend;
using GameSpecification::SpecValue;
using json = nlohmann::json;
Extend::Extend() : BaseRule(RuleType::ExtendType), target(""){}

Extend::Extend(const json& ruleJson) : BaseRule(RuleType::ExtendType){
    parseRule(ruleJson);
}

std::string Extend::getTarget() const{
    return target;
}

SpecValue Extend::getList() const{
    return list;
}

void Extend::process(GameState& gameState){
    auto variables = gameState.getVariable(target);
    if(auto retrievedValue = variables->lock()){
        // TODO: Implement ExtendVisitor
        ExtendVisitor visitor;
        retrievedValue->accept(visitor);
//        listValue.vect.insert(listValue.vect.end(), targetValue.vect.begin(), targetValue.vect.end());
    }
}

void Extend::parseRule(const json& ruleJson){
    try{
        target = ruleJson.at("target").get<std::string>();
        // json list = ruleJson.at("list");
        // if(list.is_string()){
        //     this->list.value = list.get<std::string>();
        // }else{
        //     this->list.value = list.get<std::vector<std::string>>();
        // }
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}