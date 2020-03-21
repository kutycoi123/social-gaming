#include "Case.h"

using GameSpecification::Case;
using GameSpecification::BaseRule;
using nlohmann::json;
Case::Case(){}

Case::Case(const json& ruleJson) : BaseRule(RuleType::CaseType) {

}

std::string Case::getValue(){
    return value;
}

void Case::process(GameState& gameState){

}
void Case::parseRule(const json &ruleJson){
    try{
        //TODO: Add parse code
    }catch(json::exception& e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}