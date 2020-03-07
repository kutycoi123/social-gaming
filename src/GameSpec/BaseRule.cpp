#include "BaseRule.h"

using GameSpecification::BaseRule;
using GameSpecification::RuleType;

std::unordered_map<RuleType, std::string> BaseRule::rulemap({
	{RuleType::ForEachType,"foreach"},
	{RuleType::LoopType,"loop"},
	{RuleType::InparallelType,"inparallel"},
	{RuleType::ParallelforType,"parallelfor"},
	{RuleType::SwitchType,"switch"},
	{RuleType::WhenType,"when"},
	{RuleType::ExtendType, "extend"},
	{RuleType::ReverseType, "reverse"},
	{RuleType::ShuffleType, "shuffle"},
	{RuleType::SortType, "sort"},
	{RuleType::DealType, "deal"},
	{RuleType::DiscardType, "discard"},
	{RuleType::AddType, "add"},
	{RuleType::TimerType, "timer"},
	{RuleType::InputChoiceType, "input-choice"},
	{RuleType::InputTextType, "input-text"},
	{RuleType::MessageType, "message"},
	{RuleType::GlobalMessageType, "global-message"},
	{RuleType::ScoresType, "scores"},
	{RuleType::Unknown, "unkown"}
});

BaseRule::BaseRule() : ruleType(RuleType::Unknown){}
BaseRule::BaseRule(RuleType ruleType) : 
	ruleType(ruleType){}

std::string BaseRule::getRuleName() const{
	return rulemap[ruleType];
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

	

