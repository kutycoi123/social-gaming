#ifndef SOCIALGAMING_STATEVALUELIST_H
#define SOCIALGAMING_STATEVALUELIST_H

#include <memory>
#include "StateValue.h"

class StateValueList : public StateValue {
public:
    StateValueList();
    StateValueList(const std::vector<std::shared_ptr<StateValue>>&);
    StateValue::ValueType getValueType() override;
    std::vector<std::shared_ptr<StateValue>>& getList();

    void accept(GameStateVisitor &visitor) override;

private:
    StateValue::ValueType valueType;
    std::vector<std::shared_ptr<StateValue>> stateValueList;
};

#endif //SOCIALGAMING_STATEVALUELIST_H
