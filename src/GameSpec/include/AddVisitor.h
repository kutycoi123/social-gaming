#ifndef SOCIALGAMING_ADDVISITOR_H
#define SOCIALGAMING_ADDVISITOR_H

#include "GameStateVisitor.h"

// TODO Implement methods and add error handling
class AddVisitor : public GameStateVisitor {
public:
    AddVisitor(){

    }

    void visit(StateValueBoolean &stateValue) override {
        return;
    }

    void visit(StateValueNumber &stateValue) override {
        return;
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

#endif //SOCIALGAMING_ADDVISITOR_H
