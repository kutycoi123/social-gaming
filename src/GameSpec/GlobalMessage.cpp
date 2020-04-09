#include "GlobalMessage.h"
#include "GlobalMessageVisitor.h"
#include "MessageParser.h"
#include "StateValueParser.h"
#include <iostream>

using GameSpecification::GlobalMessage;
using json = nlohmann::json;

GlobalMessage::GlobalMessage(const std::string& value) : 
    BaseRule({}), 
    value(value){}

void GlobalMessage::process(GameState& gameState) {
    auto messageParser = MessageParser(gameState, value);
    if (messageParser.hasVariable()){
        StateValueParser variable(gameState, messageParser.getVariableString().value());
        if (variable.isPerUserValue()){
            auto perUserValue = variable.getPerPlayerAudienceValue(messageParser.getVariableString().value());
            if (perUserValue.has_value()){
                // TODO: Implement per-player/user
            }
        } else {
            GlobalMessageVisitor globalMessageVisitor(gameState, messageParser, variable);
            auto stateValuePtr = variable.getStateValue(messageParser.getVariableString().value())->lock();
            if (stateValuePtr){
                stateValuePtr->accept(globalMessageVisitor);
            }
        }
    }
}
