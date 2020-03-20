#include "Message.h"
#include "MessageVisitor.h"

using GameSpecification::Message;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;
using json = nlohmann::json;

void Message::process(GameState& gameState){
    auto variables = gameState.getVariable(messValue);
    if (auto retrievedValue = variables->lock()) {
        MessageVisitor visitor;
        retrievedValue->accept(visitor);
	}
}
