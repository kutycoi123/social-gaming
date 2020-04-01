#include "StateValueNumber.h"
#include "GameStateVisitor.h"

StateValueNumber::StateValueNumber(int val) :
        value(val),
        valueType(NUMBER)
{}

StateValueNumber::StateValueNumber(double val) :
        value(val),
        valueType(NUMBER)
{}

double& StateValueNumber::getValue() {
    return value;
}

StateValue::ValueType StateValueNumber::getValueType() {
    return valueType;
}

void StateValueNumber::accept(GameStateVisitor &visitor) {
    visitor.visit(*this);
}
void StateValueNumber::accept(GameStateVisitor &visitor, StateValue* stateValue){
    StateValueNumber* t = static_cast<StateValueNumber*>(stateValue);
    visitor.visit(*this, *t);
}
