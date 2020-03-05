#include "Inparallel.h"

using GameSpecification::Inparallel;
using GameSpecification::ControlStructRule;

Inparallel::Inparallel() : ControlStructRule("inparallel"){}

void Inparallel::process(GameState& gameState){
	//TODO: Add code to process inparallel
}

void Inparallel::parseRule(const nlohmann::json &json){
	//TODO: Add parsing rule
}
