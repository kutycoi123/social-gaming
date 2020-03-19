#ifndef SOCIALGAMING_STATEVALUE_H
#define SOCIALGAMING_STATEVALUE_H

#import <string>
#import <boost/variant.hpp>

class StateValue {
public:
    enum ValueType {
        STRING,
        NUMBER,
        BOOLEAN,
        LIST,
        MAP
    };
    virtual ValueType getValueType();

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
private:
    std::vector<StateValue> stateValueList;
    StateValue::ValueType valueType;
};

// TODO: Break up into separate file
class StateValueMap : public StateValue {
public:
    StateValueMap();
    StateValue::ValueType getValueType() override;
private:
    std::unordered_map<std::string, StateValue> stateValueMap;
    StateValue::ValueType valueType;

};


#endif //SOCIALGAMING_STATEVALUE_H
