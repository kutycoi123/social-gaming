<<<<<<< HEAD
#include "Shuffle.h"
#include "ShuffleVisitor.h"
using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Shuffle::Shuffle(const std::string& list) : 
    BaseRule({}), 
    list(list)
    {}
    
void Shuffle::process(GameState& gameState) {
    auto variables = gameState.getVariable(list);
    if (auto retrievedValue = variables->lock()) {
        ShuffleVisitor visitor;
        retrievedValue->accept(visitor);
    }
}
=======
#include "Shuffle.h"

using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Shuffle::Shuffle(const std::string& list) : 
    BaseRule({}), 
    list(list)
    {}

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
>>>>>>> collecting all process methods from rules into rule parser for Jimmy
