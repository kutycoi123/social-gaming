#include "Extend.h"

#include <utility>

using GameSpecification::BaseRule;
using GameSpecification::Extend;

Extend::Extend(std::string  target, std::unique_ptr<StateValue>& list) :
    BaseRule({}), 
    target(std::move(target)),
    list(std::move(list))
    {}
    
void Extend::process(GameState& gameState){
    auto variables = gameState.getVariable(target);
    if(auto retrievedValue = variables->lock()){
        // TODO: Implement ExtendVisitor
        ExtendVisitor visitor;
        retrievedValue->accept(visitor);
//        listValue.vect.insert(listValue.vect.end(), targetValue.vect.begin(), targetValue.vect.end());
    }
}
