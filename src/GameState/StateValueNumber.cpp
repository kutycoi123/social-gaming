#include "StateValueNumber.h"

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