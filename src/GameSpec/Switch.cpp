#include "Switch.h"
using GameSpecification::Switch;

Switch::Switch(){};

Switch::Switch(const std::vector<Case>& cases): BaseRule(RuleType::Switch), cases(cases){};

std::vector<Cases> Switch::getCases() const{
    return cases;
}

void Switch::process(GameState&) override{

}

void Switch::parseRule(const json &ruleJson) override{
    
}

