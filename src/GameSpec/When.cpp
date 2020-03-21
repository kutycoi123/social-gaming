#include "When.h"
using GameSpecification::When;
using GameSpecification::BaseRule;
using GameSpecification::Case;
using json = nlohmann::json;
When::When(){};

When::When(const json &ruleJson) : BaseRule(RuleType::WhenType){
    parseRule(ruleJson);
}

const std::vector<Case>& When::getCases() const{
    return cases;
}

void When::process(GameState&){

}

void When::parseRule(const json &ruleJson){
    try{
        //TODO: Add parse code
    }catch(json::exception& e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}

