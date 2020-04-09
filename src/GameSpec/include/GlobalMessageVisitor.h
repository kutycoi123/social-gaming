#ifndef SOCIALGAMING_GLOBALMESSAGEVISITOR_H
#define SOCIALGAMING_GLOBALMESSAGEVISITOR_H

#include "GameStateVisitor.h"
#include "MessageParser.h"
#include "StateValueParser.h"

// TODO Implement methods and add error handling
class GlobalMessageVisitor : public GameStateVisitor {
public:
    GlobalMessageVisitor(GameState& state, MessageParser& parser, StateValueParser& valueParser) :
    gameState(state),
    messageParser(parser),
    stateValueParser(valueParser)
{}
    void sendMessageToEveryone(const std::string& message){
        gameState.addMessageToEntireSession(messageParser.replaceVariableString(message));
    }
    void visit(StateValueBoolean& stateValue) override {
        sendMessageToEveryone(std::to_string(stateValue.getValue()));
    }

    void visit(StateValueNumber& stateValue) override {
        sendMessageToEveryone(std::to_string(stateValue.getValue()));
    }

    void visit(StateValueString& stateValue) override {
         gameState.addMessageToEntireSession(messageParser.replaceVariableString(stateValue.getValue()));
    }

    void visit(StateValueList& stateValue) override {
        throw std::invalid_argument("Invalid parameter");
    }

    void visit(StateValueMap& stateValue) override {
        throw std::invalid_argument("Invalid parameter");
    }
	void visit(StateValueNumber& valueTobeUpdated, StateValueNumber& value) override{
        throw std::invalid_argument("Invalid parameters");
    }

    void visit(StateValueList& stateValue, StateValueList& list) override {
        throw std::invalid_argument("Invalid parameters");
    }
private:
    GameState& gameState;
    MessageParser& messageParser;
    StateValueParser& stateValueParser;
};

#endif //SOCIALGAMING_GLOBALMESSAGEVISITOR_H
