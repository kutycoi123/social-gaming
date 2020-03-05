#include "Discard.h"
using GameSpecification::Discard;
using GameSpecification::BaseRule;
Discard::Discard() : BaseRule("discard"), from(""), count(0){}

Discard::Discard(const std::string& from, const int count) : BaseRule("discard"), from(from), count(count){}

std::string Discard::getFrom() const{
    return from;
}

int Discard::getCount() const{
    return count;
}

void Discard::process(GameState& gameState) {
	//TODO: Add code to process discard rule
}

void Discard::parseRule(const nlohmann::json& json){
    //TODO: Add parsing logic
}
