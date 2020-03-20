#ifndef SOCIALGAMING_STATEVALUEMAP_H
#define SOCIALGAMING_STATEVALUEMAP_H

#include "StateValue.h"
#include <unordered_map>
#include <memory>
#include <optional>

class StateValueMap : public StateValue {
public:
    StateValueMap();
    StateValue::ValueType getValueType() override;
    std::unordered_map<std::string, std::shared_ptr<StateValue>>& getMap();
    std::optional<std::weak_ptr<StateValue>> getValue(const std::string&);
private:
    std::unordered_map<std::string, std::shared_ptr<StateValue>> stateValueMap;
    StateValue::ValueType valueType;
};

#endif //SOCIALGAMING_STATEVALUEMAP_H
