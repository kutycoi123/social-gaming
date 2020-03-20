#include "Add.h"
#include "AddVisitor.h"

using GameSpecification::Add;
using GameSpecification::SpecValue;
using json = nlohmann::json;

Add::Add(const std::string& to, const SpecValue& value) : 
    BaseRule({}), 
    to(to), 
    value(value) 
    {}

void Add::process(GameState& gameState){
        auto gameStateValue = gameState.getVariable(to);
    if (auto retrievedValue = gameStateValue->lock()) {
        // TODO: Finish add visitor implementation
        int amount = determineAmountToAdd(getValue(), gameState);

        AddVisitor visitor(amount);
        retrievedValue->accept(visitor);
    }
}


