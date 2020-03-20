#ifndef SOCIALGAMING_REVERSEVISITOR_H
#define SOCIALGAMING_REVERSEVISITOR_H

#include "GameStateVisitor.h"
#include <boost/range/algorithm/reverse.hpp>

// TODO Implement methods and add error handling
class ReverseVisitor : public GameStateVisitor {
public:
    ReverseVisitor(){

    }

    void visit(StateValueBoolean& stateValue) override {
        assert(false && "Invalid State value cannot reverse");
    }

    void visit(StateValueNumber& stateValue) override {
        assert(false && "Invalid State value cannot reverse");

    }

    void visit(StateValueString& stateValue) override {
        assert(false && "IInvalid State value cannot reverse");

    }

    void visit(StateValueList& stateValue) override {
        auto a = stateValue.getList();
        std::reverse(std::begin(a), std::end(a));
    }

    void visit(StateValueMap& stateValue) override {
        auto a = stateValue.getMap();
        std::vector<std::pair<std::string, std::shared_ptr<StateValue>>> elems(a.begin(), a.end());
        std::reverse(std::begin(elems), std::end(elems));
    }

};

#endif //SOCIALGAMING_REVERSEVISITOR_H
