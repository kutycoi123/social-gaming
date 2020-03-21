#ifndef SOCIALGAMING_ADDVISITOR_H
#define SOCIALGAMING_ADDVISITOR_H

#include "GameStateVisitor.h"

// TODO Implement methods and add error handling

bool comp(std::pair<std::string, std::shared_ptr<StateValue>> a, std::pair<std::string, std::shared_ptr<StateValue>> b) {
    return a.second < b.second;
}

class SortVisitor : public GameStateVisitor {
public:
    SortVisitor(){

    }

    void visit(StateValueBoolean& stateValue) override {
        throw std::invalid_argument("Invalid State value cannot sort");

    }

    void visit(StateValueNumber& stateValue) override {
        throw std::invalid_argument("Invalid State value cannot sort");

    }

    void visit(StateValueString& stateValue) override {
        throw std::invalid_argument("Invalid State value cannot reverse");
    }

    void visit(StateValueList& stateValue) override {
        std::sort(stateValue.getList().begin(), stateValue.getList().end());
    }
    
    void visit(StateValueMap& stateValue) override {

        auto a = stateValue.getMap();
        std::vector<std::pair<std::string, std::shared_ptr<StateValue>>> elems(a.begin(), a.end());
        std::sort(elems.begin(), elems.end(), comp);
    }

};

#endif //SOCIALGAMING_ADDVISITOR_H
