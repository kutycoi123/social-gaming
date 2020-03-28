#include "StateValueList.h"
#include "GameStateVisitor.h"

StateValueList::StateValueList() :
        valueType(StateValue::LIST)
{}


StateValueList::StateValueList(const std::vector<std::shared_ptr<StateValue>>& valueList)
    : valueType(StateValue::LIST), stateValueList(valueList)
    {}

StateValue::ValueType StateValueList::getValueType() {
    return valueType;
}

std::vector<std::shared_ptr<StateValue>>& StateValueList::getList() {
    return stateValueList;
}

void StateValueList::accept(GameStateVisitor &visitor) {
    visitor.visit(*this);
}
