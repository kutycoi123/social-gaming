#include "StateValueList.h"

StateValueList::StateValueList() :
        valueType(StateValue::LIST)
{}

StateValue::ValueType StateValueList::getValueType() {
    return valueType;
}

std::vector<std::shared_ptr<StateValue>>& StateValueList::getList() {
    return stateValueList;
}