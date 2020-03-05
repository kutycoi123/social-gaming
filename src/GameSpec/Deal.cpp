#include "Deal.h"

using GameSpecification::Deal;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;

Deal::Deal() : BaseRule("deal"), from(""), count(0){}

Deal::Deal(const std::string& from, const SpecValue& to, const int count) : BaseRule("deal"), from(from), to(to), count(count){}

std::string Deal::getFrom() const{
    return from;
}

SpecValue Deal::getTo() const{
    return to;
}

int Deal::getCount() const{
    return count;
}

void Deal::process(GameState& gameState) {
	//TODO: Add code to process deal rule
}

void Deal::parseRule(const nlohmann::json& json){
    //TODO: Add parsing logic 
}