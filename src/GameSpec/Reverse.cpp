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
    auto variables = gameState.getVariable(list);
    auto retrievedValue = variables->lock();
    type value = boost::apply_visitor(Visit_Expression(), retrievedValue.get()->value);
    //auto test = boost::get<std::unordered_map<std::string, ValueType>>(variables.value().lock().get()->value);
    //apply_visitor(ReverseVisitor(), test);
    //auto varList = test.find(list);
    //std::reverse(varList->second.begin(), varList->second.end());
}

void Reverse::parseRule(const nlohmann::json& json){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}