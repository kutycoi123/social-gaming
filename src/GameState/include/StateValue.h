#ifndef SOCIALGAMING_STATEVALUE_H
#define SOCIALGAMING_STATEVALUE_H

#include <string>
#include <vector>

class GameStateVisitor;

class StateValue {
public:
    enum ValueType {
        STRING,
        NUMBER,
        BOOLEAN,
        LIST,
        MAP
    };
    virtual ValueType getValueType() = 0;
    virtual void accept(GameStateVisitor& visitor) = 0;
};

class StateValueString : public StateValue {
public:
    explicit StateValueString(std::string val);
    std::string& getValue();
    StateValue::ValueType getValueType() override;
private:
    std::string value;
    StateValue::ValueType valueType;
};

class StateValueNumber : public StateValue {
public:
    explicit StateValueNumber(int val);
    explicit StateValueNumber(double val);
    double& getValue();
    StateValue::ValueType getValueType() override;
private:
    double value;
    StateValue::ValueType valueType;
};

class StateValueBoolean : public StateValue {
public:
    explicit StateValueBoolean(bool val);
    bool& getValue();
    StateValue::ValueType getValueType() override;
private:
    bool value;
    StateValue::ValueType valueType;
};

// TODO: Break up into separate file
class StateValueList : public StateValue {
public:
    StateValueList();
    StateValue::ValueType getValueType() override;
    std::vector<StateValue>& getList();
private:
    std::vector<StateValue> stateValueList;
    StateValue::ValueType valueType;
};

// TODO: Implement unordered_map hash function
//class StateValueMap : public StateValue {
//public:
//    StateValueMap();
//    StateValue::ValueType getValueType() override;
//private:
//    std::unordered_map<std::string, StateValue> stateValueMap;
//    StateValue::ValueType valueType;
//};


#endif //SOCIALGAMING_STATEVALUE_H
