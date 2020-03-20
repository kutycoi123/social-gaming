#include "Extend.h"
#include "ExtendVisitor.h"

using GameSpecification::BaseRule;
using GameSpecification::Extend;
using GameSpecification::SpecValue;
using json = nlohmann::json;

Extend::Extend(const std::string& target, const ValueType& list) : 
    BaseRule({}), 
    target(target), 
    list(list)
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
