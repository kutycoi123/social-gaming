#include "BaseRule.h"

using GameSpecification::BaseRule;
using nlohmann::json;

BaseRule::BaseRule(std::shared_ptr<BaseRule>& parentRule, std::shared_ptr<BaseRule>& nextRule, const std::vector<std::shared_ptr<BaseRule>>& subRules)
 : next(nextRule), parent(parentRule), subRules(subRules) {}

/*
std::shared_ptr<BaseRule> BaseRule::getPtr() {
	return ;
}
*/

/*
std::shared_ptr<BaseRule> BaseRule::getNextPtr() const {
	return next;	
}
*/