#include "StateValueBoolean.h"

StateValueBoolean::StateValueBoolean(bool val) :
        value(val),
        valueType(BOOLEAN)
{}

bool& StateValueBoolean::getValue() {
    return value;
}

StateValue::ValueType StateValueBoolean::getValueType() {
    return valueType;
}