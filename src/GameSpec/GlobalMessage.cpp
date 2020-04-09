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
            auto perUserValue = variable.getPerUserValue();
            if (perUserValue.has_value()){
                auto userValuePairList = perUserValue.value().get();
                for (const auto& userValuePair : userValuePairList){
                    GlobalMessageVisitor globalMessageVisitor(gameState, messageParser, userValuePair.user.lock());
                    userValuePair.value->accept(globalMessageVisitor);
                }
            }
        } else {
            auto stateValuePtr = variable.getStateValue()->lock();
            for (const auto& user : gameState.getPlayerList()){
                GlobalMessageVisitor globalMessageVisitor(gameState, messageParser, user.lock());
                stateValuePtr->accept(globalMessageVisitor);
            }
            for (const auto& user : gameState.getAudienceList()){
                GlobalMessageVisitor globalMessageVisitor(gameState, messageParser, user.lock());
                stateValuePtr->accept(globalMessageVisitor);
            }
        }
    }
}
