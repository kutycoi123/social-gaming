#include "StateValueMap.h"
#include "GameStateVisitor.h"

StateValueMap::StateValueMap() :
        valueType(StateValue::MAP)
{}

StateValueMap::StateValueMap(const std::unordered_map<std::string, std::shared_ptr<StateValue>>& valueMap)
    : valueType(StateValue::MAP), stateValueMap(valueMap)
    {}

StateValue::ValueType StateValueMap::getValueType() {
    return valueType;
}

std::unordered_map<std::string, std::shared_ptr<StateValue>>& StateValueMap::getMap() {
    return stateValueMap;
}

std::optional<std::weak_ptr<StateValue>> StateValueMap::getValue(const std::string& key) {
    auto it = stateValueMap.find(key);
    return (it != stateValueMap.end()) ?
           std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}

void StateValueMap::accept(GameStateVisitor &visitor) {
    visitor.visit(*this);
}
void StateValueMap::accept(GameStateVisitor &visitor, StateValue* stateValue){

}
