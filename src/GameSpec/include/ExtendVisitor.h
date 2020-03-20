#ifndef SOCIALGAMING_EXTENDVISITOR_H
#define SOCIALGAMING_EXTENDVISITOR_H

#include "GameStateVisitor.h"

// TODO Implement methods and add error handling
class ExtendVisitor : public GameStateVisitor {
public:
    ExtendVisitor(){

    }

    void visit(StateValueBoolean& stateValue) override {
        return;
    }

    void visit(StateValueNumber& stateValue) override {
        return;
    }

    void visit(StateValueString& stateValue) override {
        return;
    }

    void visit(StateValueList& stateValue) override {
        return;
    }

    void visit(StateValueMap& stateValue) override {
        return;
    }

};
#endif //SOCIALGAMING_EXTENDVISITOR_H
