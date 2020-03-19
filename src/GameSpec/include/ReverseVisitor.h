#ifndef SOCIALGAMING_REVERSEVISITOR_H
#define SOCIALGAMING_REVERSEVISITOR_H

#include "GameStateVisitor.h"
#include <boost/range/algorithm/reverse.hpp>

class ReverseVisitor : public GameStateVisitor {
public:
    ReverseVisitor(){

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
//        boost::range::reverse(stateValue.getList());
        return;
    }

//    void visit(StateValueMap &stateValue) override {
//        // TODO: How we do want to handle errors here?
//        return;
//    }

};

#endif //SOCIALGAMING_REVERSEVISITOR_H
