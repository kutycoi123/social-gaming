#include "Shuffle.h"
#include "ShuffleVisitor.h"

using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Shuffle::Shuffle() : BaseRule(RuleType::ShuffleType), list(""){}

Shuffle::Shuffle(const json &ruleJson) : BaseRule(RuleType::ShuffleType){
    parseRule(ruleJson);
}

std::string Shuffle::getList() const{
    return list;
}

void Shuffle::process(GameState& gameState) {
    auto variables = gameState.getVariable(list);
    if (auto retrievedValue = variables->lock()) {
        ShuffleVisitor visitor;
        retrievedValue->accept(visitor);
    }
}

void Shuffle::parseRule(const json &ruleJson){
    try{
        list = ruleJson.at("list").get<std::string>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}
