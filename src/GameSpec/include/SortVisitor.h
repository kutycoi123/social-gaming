#ifndef SOCIALGAMING_ADDVISITOR_H
#define SOCIALGAMING_ADDVISITOR_H

#include "GameStateVisitor.h"

class SortVisitor : public GameStateVisitor {
public:
    SortVisitor(){

    }

    void visit(StateValueBoolean &stateValue) override {
        // TODO: How we do want to handle errors here?
        return;
    }

    void visit(StateValueNumber &stateValue) override {
        // TODO: How we do want to handle errors here?
        return;
    }

    void visit(StateValueString &stateValue) override {
        // TODO: How we do want to handle errors here?
        return;
    }

    void visit(StateValueList &stateValue) override {
        // TODO: How we do want to handle errors here?
        std::sort(std::sort(stateValue.get.begin(),val.str.end()))
        return;
    }

//    void visit(StateValueMap &stateValue) override {
//        // TODO: How we do want to handle errors here?
//        return;
//    }

};

#endif //SOCIALGAMING_ADDVISITOR_H
