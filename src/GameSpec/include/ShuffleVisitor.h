#ifndef SOCIALGAMING_SHUFFLEVISITOR_H
#define SOCIALGAMING_SHUFFLEVISITOR_H

#include "GameStateVisitor.h"
#include <algorithm>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm/random_shuffle.hpp>
#include <random>

// TODO Implement methods and add error handling
class ShuffleVisitor : public GameStateVisitor {
public:
    ShuffleVisitor(){

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
//        auto value = boost::apply_visitor(Visit_Type(), retrievedValue->value);
//        auto varList = value.map;
//        auto getList = varList.find(list);
//        unsigned seed = 0;
//        auto val = boost::apply_visitor(Visit_Type(), getList->second);
//        std::shuffle(val.str.begin(), val.str.end(), std::default_random_engine(seed));
        return;
    }

    void visit(StateValueMap& stateValue) override {
        return;
    }

};

#endif //SOCIALGAMING_SHUFFLEVISITOR_H
