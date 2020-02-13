#include "ControlStructRule.h"

using GameSpecification::ControlStructRule;
using GameSpecification::BaseRule;
ControlStructRule::ControlStructRule() : BaseRule(){}

void ControlStructRule::addSubRule(std::shared_ptr<BaseRule> rule){
	_subRules.push_back(rule);
}

std::vector<std::shared_ptr<BaseRule>> ControlStructRule::getSubRules() const{
	return _subRules;
}


