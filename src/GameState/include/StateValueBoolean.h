#ifndef SOCIALGAMING_STATEVALUEBOOLEAN_H
#define SOCIALGAMING_STATEVALUEBOOLEAN_H

#include "StateValue.h"

class StateValueBoolean : public StateValue {
public:
    explicit StateValueBoolean(bool val);
    bool& getValue();
    StateValue::ValueType getValueType() override;
    void accept(GameStateVisitor &visitor) override;
    void accept(GameStateVisitor &visitor, StateValue* stateValue) override;
private:
    bool value;
    StateValue::ValueType valueType;
};

#endif //SOCIALGAMING_STATEVALUEBOOLEAN_H
