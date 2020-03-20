#include "Inparallel.h"

using GameSpecification::Inparallel;
using json = nlohmann::json;

Inparallel::Inparallel() {}

Inparallel::Inparallel(const json &ruleJson) : BaseRule(RuleType::InparallelType){
	parseRule(ruleJson);
}
void Inparallel::process(GameState& gameState){
	//TODO: Add code to process inparallel
}
