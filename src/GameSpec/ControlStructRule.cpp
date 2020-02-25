#include "ControlStructRule.h"

using GameSpecification::ControlStructRule;
using GameSpecification::BaseRule;

ControlStructRule::ControlStructRule() : BaseRule(){}

ControlStructRule::ControlStructRule(const std::string& name ) : BaseRule(name){}
void ControlStructRule::addSubRule(std::shared_ptr<BaseRule> rule){
	subRules.push_back(rule);
}

std::vector<std::shared_ptr<BaseRule>> ControlStructRule::getSubRules() const{
	return subRules;
}


