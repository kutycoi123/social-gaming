#ifndef SOCIALGAMING_ADDVISITOR_H
#define SOCIALGAMING_ADDVISITOR_H

#include "GameStateVisitor.h"

class AddVisitor : public GameStateVisitor {
public:
    AddVisitor(){

    }

    void visit(StateValueBoolean &stateValue) override {
        // TODO: How we do want to handle errors here?
        return;
    }

    void visit(StateValueNumber &stateValue) override {
        stateValue.getValueType();
    }

    void visit(StateValueString &stateValue) override {
        GameStateVisitor::visit(stateValue);
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

#endif //SOCIALGAMING_ADDVISITOR_H
