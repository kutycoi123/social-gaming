#include "BaseRule.h"

using GameSpecification::BaseRule;
using GameSpecification::RuleType;
using GameSpecification::ruleTypeToString;
using nlohmann::json;

BaseRule::BaseRule() : ruleType(RuleType::Unknown), next(nullptr), parent(nullptr){}

BaseRule::BaseRule(RuleType ruleType) : 
	ruleType(ruleType), next(nullptr), parent(nullptr){}

std::string BaseRule::getRuleName() const{
	return ruleTypeToString[ruleType];
}

RuleType BaseRule::getRuleType() const{
	return ruleType;
}
void BaseRule::addSubRule(std::shared_ptr<BaseRule> rule){
    subRules.push_back(rule);
}

std::vector<std::shared_ptr<BaseRule>> BaseRule::getSubRules() const{
    return subRules;
}

std::shared_ptr<BaseRule> BaseRule::getPtr() {
	return shared_from_this();
}
	
void BaseRule::setNextPtr(const std::shared_ptr<BaseRule>& ptr){
	next = std::shared_ptr<BaseRule>(ptr);
}

std::shared_ptr<BaseRule> BaseRule::getNextPtr() const {
	return next;	
}

void BaseRule::setParentPtr(const std::shared_ptr<BaseRule>& ptr) {
	parent = std::shared_ptr<BaseRule>(ptr);
}

std::shared_ptr<BaseRule> BaseRule::getParentPtr() const{
	return parent;
}
