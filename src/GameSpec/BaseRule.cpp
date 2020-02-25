#include "BaseRule.h"

using GameSpecification::BaseRule;
using GameSpecification::RuleType;

std::unordered_map<std::string, RuleType> BaseRule::rulemap({
	{"foreach", RuleType::ForEachType},
	{"loop", RuleType::LoopType},
	{"inparallel", RuleType::InparallelType},
	{"parallelfor", RuleType::ParallelforType},
	{"switch", RuleType::SwitchType},
	{"when", RuleType::WhenType},
	{"extend", RuleType::ExtendType},
	{"reverse", RuleType::ReverseType},
	{"shuffle", RuleType::ShuffleType},
	{"sort", RuleType::SortType},
	{"deal", RuleType::DealType},
	{"discard", RuleType::DiscardType},
	{"add", RuleType::AddType},
	{"timer", RuleType::TimerType},
	{"input-choice", RuleType::InputChoiceType},
	{"input-text", RuleType::InputTextType},
	{"message", RuleType::MessageType},
	{"global-message", RuleType::GlobalMessageType},
	{"scores", RuleType::ScoresType}
});

BaseRule::BaseRule(){}
BaseRule::BaseRule(const std::string& ruleName) : 
	ruleType(getRuleTypeFromName(ruleName)), 
	ruleName(ruleName)	{}
std::string BaseRule::getRuleName() const{
	return ruleName;
}

void BaseRule::setRuleName(const std::string& ruleName){
	this-> ruleName = ruleName;
	ruleType = getRuleTypeFromName(ruleName);
}

RuleType BaseRule::getRuleType() const{
	return ruleType;
}

RuleType BaseRule::getRuleTypeFromName(const std::string& name){
	auto type = rulemap.find(name);
	if(type == rulemap.end())	
		return RuleType::Unknown;
	return type->second;
}
	

