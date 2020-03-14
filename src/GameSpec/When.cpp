#include "When.h"
using GameSpecification::When;

When::When(){};

When::When(const std::vector<Case>& cases): BaseRule(RuleType::When), cases(cases){};

std::vector<Cases> When::getCases() const{
    return cases;
}

void When::process(GameState&) override{

}

void When::parseRule(const json &ruleJson) override{

}

