#include "BaseRule.h"

using GameSpecification::BaseRule;
using GameSpecification::RuleType;

std::unordered_map<std::string, RuleType> BaseRule::rulemap({
	{"foreach", RuleType::ForEach},
	{"loop", RuleType::Loop},
	{"Inparallel", RuleType::Inparallel},
	{"parallelfor", RuleType::Parallelfor},
	{"switch", RuleType::Switch},
	{"when", RuleType::When},
	{"extend", RuleType::Extend},
	{"reverse", RuleType::Reverse},
	{"shuffle", RuleType::Shuffle},
	{"sort", RuleType::Sort},
	{"deal", RuleType::Deal},
	{"discard", RuleType::Discard},
	{"add", RuleType::Add},
	{"timer", RuleType::Timer},
	{"input-choice", RuleType::InputChoice},
	{"input-text", RuleType::InputText},
	{"message", RuleType::Message},
	{"global-message", RuleType::GlobalMessage},
	{"scores", RuleType::Scores}
});

BaseRule::BaseRule(){}
BaseRule::BaseRule(const std::string& ruleName) : 
	_ruleType(getRuleTypeFromName(ruleName)), 
	_ruleName(ruleName)	{}
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
	auto type = rulemap.find(name);
	if(type == rulemap.end())	
		return RuleType::Unknown;
	return type->second;
}
	

