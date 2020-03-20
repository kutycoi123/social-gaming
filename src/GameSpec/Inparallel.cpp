#include "Inparallel.h"

using GameSpecification::Inparallel;
using json = nlohmann::json;

Inparallel::Inparallel(const std::list<std::shared_ptr<BaseRule>>& childRules) :
	BaseRule(childRules)
	{}

Inparallel::Inparallel(const json &ruleJson) : BaseRule(RuleType::InparallelType){
	parseRule(ruleJson);
}
void Inparallel::process(GameState& gameState){
	//TODO: Add code to process inparallel
}
