#include "Inparallel.h"

using GameSpecification::Inparallel;
using GameSpecification::ControlStructRule;
using json = nlohmann::json;
Inparallel::Inparallel() : ControlStructRule("inparallel"){}

void Inparallel::process(GameState& gameState){
	//TODO: Add code to process inparallel
}

void Inparallel::parseRule(const json &ruleJson){
	try{

	}catch(json::exception &e){
		std::cout << e.what() << "\n";
	}
}
