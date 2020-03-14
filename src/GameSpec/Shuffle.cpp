#include "Shuffle.h"

using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Shuffle::Shuffle() : BaseRule(RuleType::ShuffleType), list(""){}

Shuffle::Shuffle(const std::string& list): BaseRule(RuleType::ShuffleType), list(list){}

std::string Shuffle::getList() const{
    return list;
}

void Shuffle::process(GameState& gameState){
	//TODO: Add code to process shuffle rule
}

void Shuffle::parseRule(const json &ruleJson){
    try{
        list = ruleJson.at("list").get<std::string>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}
