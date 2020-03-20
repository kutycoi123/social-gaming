#ifndef SOCIALGAMING_STATEVALUELIST_H
#define SOCIALGAMING_STATEVALUELIST_H

#include "StateValue.h"

class StateValueList : public StateValue {
public:
    StateValueList();
    StateValue::ValueType getValueType() override;
    std::vector<StateValue>& getList();
private:
    std::vector<StateValue> stateValueList;
    StateValue::ValueType valueType;
};

#endif //SOCIALGAMING_STATEVALUELIST_H
