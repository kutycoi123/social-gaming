//
// Created by josh on 2020-03-19.
//

#ifndef SOCIALGAMING_STATEVALUENUMBER_H
#define SOCIALGAMING_STATEVALUENUMBER_H

#include "StateValue.h"

class StateValueNumber : public StateValue {
public:
    explicit StateValueNumber(int val);
    explicit StateValueNumber(double val);
    int& getValue();
    StateValue::ValueType getValueType() override;

    void accept(GameStateVisitor &visitor) override;
    void accept(GameStateVisitor &visitor, StateValue* stateValue) override;

private:
    int value;
    StateValue::ValueType valueType;
};


#endif //SOCIALGAMING_STATEVALUENUMBER_H
