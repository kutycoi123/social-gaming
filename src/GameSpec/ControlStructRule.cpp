#include "ControlStructRule.h"

using GameSpecification::ControlStructRule;
using GameSpecification::BaseRule;

ControlStructRule::ControlStructRule() : BaseRule(){}

ControlStructRule::ControlStructRule(RuleType ruleType ) : BaseRule(ruleType){}
void ControlStructRule::addSubRule(std::shared_ptr<BaseRule> rule){
	subRules.push_back(rule);
}

std::vector<std::shared_ptr<BaseRule>> ControlStructRule::getSubRules() const{
	return subRules;
}


