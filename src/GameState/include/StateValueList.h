#ifndef SOCIALGAMING_STATEVALUELIST_H
#define SOCIALGAMING_STATEVALUELIST_H

#include <memory>
#include "StateValue.h"

class StateValueList : public StateValue {
public:
    StateValueList();
    StateValue::ValueType getValueType() override;
    std::vector<std::shared_ptr<StateValue>>& getList();

    void accept(GameStateVisitor &visitor) override;

private:
    std::vector<std::shared_ptr<StateValue>> stateValueList;
    StateValue::ValueType valueType;
};

#endif //SOCIALGAMING_STATEVALUELIST_H
