#ifndef SOCIALGAMING_EXTENDVISITOR_H
#define SOCIALGAMING_EXTENDVISITOR_H

#include "GameStateVisitor.h"

class ExtendVisitor : public GameStateVisitor {
public:
    ExtendVisitor(){

    }

    void visit(StateValueBoolean &stateValue) override {
        // TODO: How we do want to handle errors here?
        return;
    }

    void visit(StateValueNumber &stateValue) override {
        return;
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
#endif //SOCIALGAMING_EXTENDVISITOR_H
