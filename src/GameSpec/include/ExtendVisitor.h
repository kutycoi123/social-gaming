#ifndef SOCIALGAMING_EXTENDVISITOR_H
#define SOCIALGAMING_EXTENDVISITOR_H

#include "GameStateVisitor.h"

// TODO Implement methods and add error handling
class ExtendVisitor : public GameStateVisitor {
public:
    ExtendVisitor(){

    }

    void visit(StateValueBoolean& stateValue) override {
        throw std::invalid_argument("Invalid State value cannot extend");
    }

    void visit(StateValueNumber& stateValue) override {
        throw std::invalid_argument("Invalid State value cannot extend");
    }

    void visit(StateValueString& stateValue) override {
        throw std::invalid_argument("Invalid State value cannot extend");
    }

    void visit(StateValueList& stateValue) override {
        auto target = stateValue.getList();
        //TODO How to get the other Vector of type SpecValue to extend with

//        auto valueList = stateValue.getList();
//        valueList.insert(valueList.end(), target.begin(), target.end());
    }

    void visit(StateValueMap& stateValue) override {
        auto target = stateValue.getMap();
        //TODO How to get the other Map of type SpecValue to extend with
        //auto valueList = stateValue.getMap();
        //valueList.insert(target.begin(), target.end());
    }
    void visit(StateValueNumber& valueTobeUpdated, StateValueNumber& value) override{

    }

};
#endif //SOCIALGAMING_EXTENDVISITOR_H
