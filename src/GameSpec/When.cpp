#include "When.h"

using GameSpecification::When;
using GameSpecification::BaseRule;
using GameSpecification::WhenCase;

When::When(const std::vector<WhenCase>& cases) : 
    BaseRule({}),
    cases(cases)
    {}

void When::process(GameState&){

}

WhenCase::WhenCase(const std::string& condition, const std::list<std::shared_ptr<BaseRule>>& rules) :
    condition(condition),
    rules(rules)
    {}
