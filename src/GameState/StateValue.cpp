#include "StateValue.h"

#include <utility>


StateValueList::StateValueList() :
    valueType(StateValue::LIST)
{}

StateValue::ValueType StateValueList::getValueType() {
    return valueType;
}

std::vector<StateValue>& StateValueList::getList() {
    return stateValueList;
}

//StateValueMap::StateValueMap() :
//        valueType(StateValue::MAP)
//{}
//
//StateValue::ValueType StateValueMap::getValueType() {
//    return valueType;
//}

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
