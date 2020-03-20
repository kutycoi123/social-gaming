#include "StateValueString.h"

StateValueString::StateValueString(std::string val) :
        value(std::move(val)),
        valueType(STRING)
{}

std::string& StateValueString::getValue() {
    return value;
}

StateValue::ValueType StateValueString::getValueType() {
    return valueType;
}
