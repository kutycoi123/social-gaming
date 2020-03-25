#include "Message.h"

#include <utility>
#include "MessageVisitor.h"

using GameSpecification::Message;
using GameSpecification::BaseRule;

Message::Message(const std::shared_ptr<StateValue>& to, std::string val) :
    BaseRule({}),
    to(to), 
    messValue(std::move(val))
    {}

void Message::process(GameState& gameState){
    auto variables = gameState.getVariable(messValue);
    if (auto retrievedValue = variables->lock()) {
        MessageVisitor visitor;
        retrievedValue->accept(visitor);
	}
}
