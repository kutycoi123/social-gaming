
#ifndef SOCIALGAMING_DEALVISITOR_H
#define SOCIALGAMING_DEALVISITOR_H

#include "GameStateVisitor.h"

// TODO Implement methods and add error handling
class DealVisitor : public GameStateVisitor {
public:
    DealVisitor(){

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


#endif //SOCIALGAMING_DEALVISITOR_H
