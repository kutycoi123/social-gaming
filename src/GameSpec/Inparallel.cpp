#include "Inparallel.h"

using GameSpecification::Inparallel;
using json = nlohmann::json;

Inparallel::Inparallel() : BaseRule(RuleType::InparallelType){}

Inparallel::Inparallel(const json &ruleJson) : BaseRule(RuleType::InparallelType){
	parseRule(ruleJson);
}
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
