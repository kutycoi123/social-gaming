#include "Add.h"

using GameSpecification::Add;
using GameSpecification::SpecValue;
using json = nlohmann::json;

Add::Add() : BaseRule(RuleType::AddType), to(""){}

Add::Add(const std::string& to, const SpecValue& value) 
    : BaseRule(RuleType::AddType), to(to), value(value){}

std::string Add::getTo() const{
    return to;
}
SpecValue Add::getValue() const{
    return value;
}

void Add::process(GameState& gameState){
    auto gameStateValue = gameState.getVariable(to);
    if (!gameStateValue.has_value()){
        return;
    }

    if (auto gsValue = gameStateValue->lock()) {
        auto existingValue = gsValue->value.value;
        int v1 = boost::get<int>(existingValue);
        
        auto addedValue = getValue().value;
        int v2 = 0;

        if (boost::get<int>(addedValue)) {
            v2 = boost::get<int>(addedValue);
        } else {
            auto variableToAdd = gameState.getVariable(boost::get<std::string>(addedValue));
            auto constantToAdd = gameState.getConstant(boost::get<std::string>(addedValue));
            if (variableToAdd.has_value()) {
                auto vValue = variableToAdd->lock();
                v2 = boost::get<int>(vValue->value.value);
            }

            if (constantToAdd.has_value()) {
                auto cValue = variableToAdd->lock();
                v2 = boost::get<int>(cValue->value.value);
            }
        }

        gsValue->value.value = v1 + v2;        
    }

}
void Add::parseRule(const json& ruleJson){
    try{

    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}