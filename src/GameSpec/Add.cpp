#include "Add.h"

using GameSpecification::Add;
using GameSpecification::SpecValue;
Add::Add() : BaseRule("add"), to(""){}

Add::Add(const std::string& to, const SpecValue& value) : BaseRule("add"), to(to), value(value){}

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
    auto a = gameState.getVariables(to);

    if (a.has_value()) {
        auto retrievedValue = a.value().get().value;

        auto existingValue = boost::get<int>(this->value.value);
        auto newValue = boost::get<int>(retrievedValue);
        boost::variant<std::string, int, bool, double> result = newValue + existingValue;

        gameState.setVariable(to, result);
    }
}
void Add::parseRule(const nlohmann::json& json){
    //TODO: Add parsing logic 
}