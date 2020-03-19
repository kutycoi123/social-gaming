#ifndef SOCIALGAMING_GLOBALMESSAGEVISITOR_H
#define SOCIALGAMING_GLOBALMESSAGEVISITOR_H

#include "GameStateVisitor.h"

// TODO Implement methods and add error handling
class GlobalMessageVisitor : public GameStateVisitor {
public:
    GlobalMessageVisitor(){

    }

    void visit(StateValueBoolean &stateValue) override {
        return;
    }

    void visit(StateValueNumber &stateValue) override {
        stateValue.getValueType();
    }

    void visit(StateValueString &stateValue) override {
        return;
    }

    void visit(StateValueList &stateValue) override {
        return;
    }

//    void visit(StateValueMap &stateValue) override {
//        return;
//    }

};

#endif //SOCIALGAMING_GLOBALMESSAGEVISITOR_H
