#ifndef SOCIALGAMING_GAMESTATEVISITOR_H
#define SOCIALGAMING_GAMESTATEVISITOR_H

#include "StateValue.h"

class GameStateVisitor {
public:
    virtual void visit(StateValueBoolean& stateValue) = 0;
    virtual void visit(StateValueNumber& stateValue) = 0;
    virtual void visit(StateValueString& stateValue) = 0;
    virtual void visit(StateValueList& stateValue) = 0;
//    virtual void visit(StateValueMap& stateValue);
};

#endif