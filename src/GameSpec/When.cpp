//#include "When.h"
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
