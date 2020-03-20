#include "Switch.h"
using GameSpecification::Switch;
using GameSpecification::BaseRule;
using GameSpecification::Case;
using json = nlohmann::json;

<<<<<<< HEAD
Switch::Switch() : BaseRule(RuleType::SwitchType){}
=======
/*
Switch::Switch(){};
>>>>>>> working on centralized parsing

Switch::Switch(const json &ruleJson) : BaseRule(RuleType::SwitchType){
    parseRule(ruleJson);
}

const std::vector<Case>& Switch::getCases() const{
    return cases;
}
*/

void Switch::process(GameState&){

}