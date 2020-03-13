#include "StateValue.h"

StateValueLiteral::StateValueLiteral(const std::string &val) :
    value(val),
    valueType(StateValue::STRING)
{}

StateValueLiteral::StateValueLiteral(int val) :
        value(val),
        valueType(StateValue::INT)
{}

StateValueLiteral::StateValueLiteral(double val) :
    value(val),
    valueType(StateValue::DOUBLE)
{}

StateValueLiteral::StateValueLiteral(bool val) :
    value(val),
    valueType(StateValue::BOOLEAN)
{}

StateValue::ValueType StateValueLiteral::getValueType() {
    return StateValue::getValueType();
}

boost::variant<std::string, int,
        bool, double> &StateValueLiteral::getValue() {
    return value;
}

StateValueList::StateValueList() :
    valueType(StateValue::LIST)
{}

StateValue::ValueType StateValueList::getValueType() {
    return valueType;
}

StateValueMap::StateValueMap() :
        valueType(StateValue::MAP)
{}

StateValue::ValueType StateValueMap::getValueType() {
    return valueType;
}