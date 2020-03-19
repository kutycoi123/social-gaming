#ifndef SOCIALGAMING_REVERSEVISITOR_H
#define SOCIALGAMING_REVERSEVISITOR_H

#include "GameStateVisitor.h"
#include <boost/range/algorithm/reverse.hpp>

// TODO Implement methods and add error handling
class ReverseVisitor : public GameStateVisitor {
public:
    ReverseVisitor(){

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
//        boost::range::reverse(stateValue.getList());
        return;
    }

//    void visit(StateValueMap &stateValue) override {
//        return;
//    }

};

#endif //SOCIALGAMING_REVERSEVISITOR_H
