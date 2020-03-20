#include "Discard.h"
#include "DiscardVisitor.h"

using GameSpecification::Discard;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Discard::Discard(const std::string& from, const int count) : 
    BaseRule({}), 
    from(from), 
    count(count)
    {}

void Discard::process(GameState& gameState) {
	//TODO: Add code to process discard rule
    auto gameStateValueFrom = gameState.getVariable(from);
    
    if (auto fromList = gameStateValueFrom->lock()) {

        DiscardVisitor visitor(getCount());
        fromList->accept(visitor);
    }
}
