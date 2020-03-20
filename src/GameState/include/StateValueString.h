
#ifndef SOCIALGAMING_STATEVALUESTRING_H
#define SOCIALGAMING_STATEVALUESTRING_H

#include <string>
#include "StateValue.h"

class StateValueString : public StateValue {
public:
    explicit StateValueString(std::string val);
    std::string& getValue();
    StateValue::ValueType getValueType() override;

    void accept(GameStateVisitor &visitor) override;

private:
    std::string value;
    StateValue::ValueType valueType;
};


#endif //SOCIALGAMING_STATEVALUESTRING_H
