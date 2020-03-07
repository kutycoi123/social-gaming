#include <random>
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
    auto variables = gameState.getVariables(list);
    auto test = boost::get<std::unordered_map<std::string, std::string>>(variables.value().get().value);
    unsigned seed = 0;
    auto varList = test.find(list);
    std::shuffle(varList->second.begin(), varList->second.end(), std::default_random_engine(seed));

}

void Shuffle::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}
