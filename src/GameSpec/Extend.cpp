#include "Extend.h"

using GameSpecification::BaseRule;
using GameSpecification::Extend;
using GameSpecification::SpecValue;
Extend::Extend() : BaseRule("extend"), target(""){}

Extend::Extend(const std::string& target, const SpecValue& list) : BaseRule("extend"), target(target), list(list){}

std::string Extend::getTarget() const{
    return target;
}

SpecValue Extend::getList() const{
    return list;
}

void Extend::process(GameState& gameState){
	//TODO: Add code to process extend rule
}

void Extend::parseRule(const nlohmann::json& json){
    //TODO: Add parsing logic
}