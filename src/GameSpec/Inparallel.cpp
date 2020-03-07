#include "Inparallel.h"

using GameSpecification::Inparallel;
using GameSpecification::ControlStructRule;
using json = nlohmann::json;
Inparallel::Inparallel() : BaseRule(RuleType::InparallelType){}

void Inparallel::process(GameState& gameState){
	//TODO: Add code to process inparallel
}

void Inparallel::parseRule(const json &ruleJson){
	try{

	}catch(json::exception &e){
		//TODO: Handle exception more properly
		std::cout << e.what() << "\n";
	}
}
