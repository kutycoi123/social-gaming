#ifndef SOCIALGAMING_ADDVISITOR_H
#define SOCIALGAMING_ADDVISITOR_H

#include "GameStateVisitor.h"

// TODO Implement methods and add error handling
class AddVisitor : public GameStateVisitor {
public:
    AddVisitor(){}
    AddVisitor(int num) : valueToAdd(num){};

    void visit(StateValueBoolean& stateValue) override {
        throw std::invalid_argument("Invalid State value, cannot add");
    }

    void visit(StateValueNumber& stateValue) override {
        double value = stateValue.getValue();
        stateValue.getValue() = value + valueToAdd;
    }

    void visit(StateValueString& stateValue) override {
        throw std::invalid_argument("Invalid State value, cannot add");
    }

    void visit(StateValueList& stateValue) override {
        throw std::invalid_argument("Invalid State value, cannot add");
    }

    void visit(StateValueMap& stateValue) override {
        throw std::invalid_argument("Invalid State value, cannot add");
    }

    void visit(StateValueNumber& stateValue1, StateValueNumber& stateValue2) override{
        double value = stateValue1.getValue();
        stateValue2.getValue() = value + stateValue2.getValue();
    }

private:
    int valueToAdd = 0;
};

#endif //SOCIALGAMING_ADDVISITOR_H
