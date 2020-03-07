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
	// TODO: Add code to process add rule
    // TODO: Find a better way to wrap and unwrap boost variant
    // TODO: Handle cases not just for int
    auto a = gameState.getVariable(to);
    if (!a.has_value()){
        return;
    }
    if (auto retrievedValue = a->lock()) {
        auto existingValue = boost::get<int>(this->value.value);
        auto newValue = boost::get<int>(retrievedValue->value);
        boost::variant<std::string, int, bool, double> result = newValue + existingValue;

        retrievedValue->value = result;
    }
}
void Add::parseRule(const json& ruleJson){
    try{

    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}