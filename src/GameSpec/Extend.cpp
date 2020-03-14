#include "Extend.h"

using GameSpecification::BaseRule;
using GameSpecification::Extend;
using GameSpecification::SpecValue;
using json = nlohmann::json;
Extend::Extend() : BaseRule(RuleType::ExtendType), target(""){}

Extend::Extend(const std::string& target, const ValueType& list) : BaseRule(RuleType::ExtendType), target(target), list(list){}

std::string Extend::getTarget() const{
    return target;
}

ValueType Extend::getList() const{
    return list;
}

void Extend::process(GameState& gameState){
    auto variables = gameState.getVariable(target);
    if(auto retrievedValue = variables->lock()){
        auto targetValue = boost::apply_visitor(Visit_Type(), retrievedValue->value);
        auto listValue = boost::apply_visitor(Visit_Type(), list);
        listValue.vect.insert(listValue.vect.end(), targetValue.vect.begin(), targetValue.vect.end());
    }
}

void Extend::parseRule(const json& ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}