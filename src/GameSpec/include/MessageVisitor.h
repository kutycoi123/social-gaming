//
// Created by josh on 2020-03-19.
//

#ifndef SOCIALGAMING_MESSAGEVISITOR_H
#define SOCIALGAMING_MESSAGEVISITOR_H

#include "GameStateVisitor.h"

class MessageVisitor : public GameStateVisitor {
public:
    MessageVisitor(){

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
        return;
    }

//    void visit(StateValueMap &stateValue) override {
//        // TODO: How we do want to handle errors here?
//        return;
//    }

};

#endif //SOCIALGAMING_MESSAGEVISITOR_H
