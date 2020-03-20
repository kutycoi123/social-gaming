#include "BaseRule.h"

using GameSpecification::BaseRule;
using nlohmann::json;

BaseRule::BaseRule(const std::list<std::shared_ptr<BaseRule>>& childs)
 : childRules(childs) {}

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