#include "Message.h"
#include "MessageVisitor.h"

using GameSpecification::Message;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;

Message::Message(const SpecValue& to, const std::string& val) : 
    BaseRule({}),
    to(to), 
    messValue(val)
    {}

void Message::process(GameState& gameState){
    auto variables = gameState.getVariable(messValue);
    if (auto retrievedValue = variables->lock()) {
        MessageVisitor visitor;
        retrievedValue->accept(visitor);
	}
}
