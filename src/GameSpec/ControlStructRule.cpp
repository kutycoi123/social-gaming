#include "ControlStructRule.h"

using GameSpecification::ControlStructRule;
using GameSpecification::BaseRule;
ControlStructRule::ControlStructRule() : BaseRule(){}

ControlStructRule::ControlStructRule(const std::string& ruleName) : BaseRule(ruleName) {}

void ControlStructRule::addSubRule(const BaseRule& rule){
	_subRules.push_back(std::make_shared<BaseRule>(rule));
}

std::vector<std::shared_ptr<BaseRule>> ControlStructRule::getSubRules() const{
	return _subRules;
}

void ControlStructRule::processRules(){
	//TODO: Add logic for rule 
}
