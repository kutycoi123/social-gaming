#include "StateValueList.h"
#include "GameStateVisitor.h"

StateValueList::StateValueList() :
        valueType(StateValue::LIST)
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
void StateValueList::accept(GameStateVisitor &visitor, StateValue* stateValue){

}
