#include "Switch.h"
using GameSpecification::Switch;
using GameSpecification::BaseRule;
using GameSpecification::Case;
using json = nlohmann::json;

Switch::Switch() : BaseRule(RuleType::SwitchType){}

Switch::Switch(const json &ruleJson) : BaseRule(RuleType::SwitchType){
    parseRule(ruleJson);
}

const std::vector<Case>& Switch::getCases() const{
    return cases;
}

void Switch::process(GameState&){

}

void Switch::parseRule(const json &ruleJson){
    try{
        //TODO: Add parse code
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}

