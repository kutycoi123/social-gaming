#ifndef SOCIALGAMING_DISCARDVISITOR_H
#define SOCIALGAMING_DISCARDVISITOR_H


#include "GameStateVisitor.h"

// TODO Implement methods and add error handling
class DiscardVisitor : public GameStateVisitor {
public:
    DiscardVisitor(){

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


#endif //SOCIALGAMING_DISCARDVISITOR_H
