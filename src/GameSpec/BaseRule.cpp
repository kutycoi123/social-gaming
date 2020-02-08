#include "BaseRule.h"

using GameSpecification::BaseRule;
using GameSpecification::RuleType;
BaseRule::BaseRule(){}

BaseRule::BaseRule(const std::string& ruleName) : _ruleName(ruleName), _ruleType(getRuleTypeFromName(ruleName)){}

std::string BaseRule::getRuleName() const{
	return _ruleName;
}

void BaseRule::setRuleName(const std::string& ruleName){
	_ruleName = ruleName;
	_ruleType = getRuleTypeFromName(ruleName);
}

RuleType BaseRule::getRuleType() const{
	return _ruleType;
}

RuleType BaseRule::getRuleTypeFromName(const std::string& name){
	/*
	switch(name){
		case "foreach":
			return RuleType::ForEach;
		case "loop":
			return RuleType::Loop;
		case "inparallel":
			return RuleType::Inparallel;
		case "parallelfor":
			return RuleType::Parallelfor;
		case "switch":
			return RuleType::Switch;
		case "when":
			return RuleType::When;
		case "extend":
			return RuleType::Extend;
		case "reverse":
			return RuleType::Reverse;
		case "shuffle":
			return RuleType::Shuffle;
		case "sort":
			return RuleType::Sort;
		case "deal":
			return RuleType::Deal;
		case "discard":
			return RuleType::Discard;
		case "add":
			return RuleType::Add;
		case "timer":
			return RuleType::Timer;
		case "input-choice":
			return RuleType::InputChoice;
		case "input-text":
			return RuleType::InputText;
		case "input-vote":
			return RuleType::InputVote;
		case "message":
			return RuleType::Message;
		case "global-message":
			return RuleType::GlobalMessage
		case "scores":
			return RuleType::Scores;
		default:
			return RuleType::Unknown;
	*/

	return RuleType::Unknown;
	}
	

