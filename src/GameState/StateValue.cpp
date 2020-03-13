#include "StateValue.h"

StateValue::StateValue(const std::string &val) :
    value(val),
    valueType(STRING)
{}

StateValue::StateValue(int val) :
        value(val),
        valueType(INT)
{}

StateValue::StateValue(double val) :
    value(val),
    valueType(DOUBLE)
{}

StateValue::StateValue(bool val) :
    value(val),
    valueType(BOOLEAN)
{}

StateValue::ValueType StateValue::getValueType() {
    return valueType;
}

boost::variant<std::string, int,
        bool, double>& StateValue::getValue() {
    return value;
}
