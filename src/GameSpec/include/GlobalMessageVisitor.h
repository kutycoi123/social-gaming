#ifndef SOCIALGAMING_GLOBALMESSAGEVISITOR_H
#define SOCIALGAMING_GLOBALMESSAGEVISITOR_H

#include "GameStateVisitor.h"

class GlobalMessageVisitor : public GameStateVisitor {
public:
    GlobalMessageVisitor(){

    }

    void visit(StateValueBoolean &stateValue) override {
        // TODO: How we do want to handle errors here?
        return;
    }

    void visit(StateValueNumber &stateValue) override {
        stateValue.getValueType();
    }

    void visit(StateValueString &stateValue) override {
        return;
    }

    void visit(StateValueList &stateValue) override {
        // TODO: How we do want to handle errors here?
        return;
    }

//    void visit(StateValueMap &stateValue) override {
//        // TODO: How we do want to handle errors here?
//        return;
//    }

};

#endif //SOCIALGAMING_GLOBALMESSAGEVISITOR_H
