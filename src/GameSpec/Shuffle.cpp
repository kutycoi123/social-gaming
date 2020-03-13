#include <random>
#include <boost/range/algorithm.hpp>
#include "Shuffle.h"
#include <algorithm>
#include <boost/range/algorithm/random_shuffle.hpp>


using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Shuffle::Shuffle() : BaseRule(RuleType::ShuffleType), list(""){}

Shuffle::Shuffle(const std::string& list): BaseRule(RuleType::ShuffleType), list(list){}

std::string Shuffle::getList() const{
    return list;
}

void Shuffle::process(GameState& gameState) {
    auto variables = gameState.getVariable(list);
    if (auto retrievedValue = variables->lock()) {
        auto value = boost::apply_visitor(Visit_Type(), retrievedValue->value);
        auto varList = value.map;
        auto getList = varList.find(list);
        unsigned seed = 0;
        auto val = boost::apply_visitor(Visit_Type(), getList->second);
        std::shuffle(val.str.begin(), val.str.end(), std::default_random_engine(seed));
    }
}

void Shuffle::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}
