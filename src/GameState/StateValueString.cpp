#include "StateValueString.h"
#include "GameStateVisitor.h"

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

void StateValueString::accept(GameStateVisitor &visitor) {
    visitor.visit(*this);
}
