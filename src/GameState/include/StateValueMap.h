#ifndef SOCIALGAMING_STATEVALUEMAP_H
#define SOCIALGAMING_STATEVALUEMAP_H

#include "StateValue.h"
#include <unordered_map>
#include <memory>
#include <optional>

class StateValueMap : public StateValue {
public:
    StateValueMap();
    StateValueMap(const std::unordered_map<std::string, std::shared_ptr<StateValue>>&);
    StateValue::ValueType getValueType() override;
    std::unordered_map<std::string, std::shared_ptr<StateValue>>& getMap();
    std::optional<std::weak_ptr<StateValue>> getValue(const std::string&);

    void accept(GameStateVisitor &visitor) override;

private:
    StateValue::ValueType valueType;
    std::unordered_map<std::string, std::shared_ptr<StateValue>> stateValueMap;
};

#endif //SOCIALGAMING_STATEVALUEMAP_H
