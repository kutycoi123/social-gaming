#include "Shuffle.h"

using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
using json = nlohmann::json;
Shuffle::Shuffle() : BaseRule("shuffle"), list(""){}

Shuffle::Shuffle(const std::string& list): BaseRule("shuffle"), list(list){}

std::string Shuffle::getList() const{
    return list;
}

void Shuffle::process(GameState& gameState){
	//TODO: Add code to process shuffle rule
}

void Shuffle::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}
