#ifndef SOCIALGAMING_GLOBALMESSAGEVISITOR_H
#define SOCIALGAMING_GLOBALMESSAGEVISITOR_H

#include "GameStateVisitor.h"
#include "MessageParser.h"
#include "StateValueParser.h"

class GlobalMessageVisitor : public GameStateVisitor {
public:
    GlobalMessageVisitor(GameState& state, MessageParser& parser, const std::shared_ptr<User>& user) :
    gameState(state),
    messageParser(parser),
    user(user)
{}
    void sendMessageToUser(const std::string& message){
        gameState.addMessage(user->getUserId(), messageParser.replaceVariableString(message));
    }
    void visit(StateValueBoolean& stateValue) override {
        sendMessageToUser(std::to_string(stateValue.getValue()));
    }

    void visit(StateValueNumber& stateValue) override {
        sendMessageToUser(std::to_string(stateValue.getValue()));
    }

    void visit(StateValueString& stateValue) override {
        sendMessageToUser(stateValue.getValue());
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
    std::shared_ptr<User> user;
};

#endif //SOCIALGAMING_GLOBALMESSAGEVISITOR_H
