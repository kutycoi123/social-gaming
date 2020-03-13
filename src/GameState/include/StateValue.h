//
// Created by josh on 2020-03-13.
//

#ifndef SOCIALGAMING_STATEVALUE_H
#define SOCIALGAMING_STATEVALUE_H

#import <string>
#import <boost/variant.hpp>

class StateValue {
public:
    enum ValueType {
        STRING,
        INT,
        DOUBLE,
        BOOLEAN,
        LIST,
        MAP
    };
    virtual ValueType getValueType();

};

// TODO: Break up into separate file
class StateValueLiteral : public StateValue {
public:
    explicit StateValueLiteral(const std::string& val);
    explicit StateValueLiteral(int val);
    explicit StateValueLiteral(double val);
    explicit StateValueLiteral(bool val);
    boost::variant<std::string, int,
            bool, double>& getValue();
    StateValue::ValueType getValueType() override;
private:
    boost::variant<std::string, int,
            bool, double> value;
    StateValue::ValueType valueType;
};

// TODO: Break up into separate file
class StateValueList : public StateValue {
public:
    StateValueList();
    StateValue::ValueType getValueType() override;
private:
    std::vector<StateValueLiteral> stateValueList;
    StateValue::ValueType valueType;
};

// TODO: Break up into separate file
class StateValueMap : public StateValue {
public:
    StateValueMap();
    StateValue::ValueType getValueType() override;
private:
    std::unordered_map<std::string, StateValueLiteral> stateValueMap;
    StateValue::ValueType valueType;

};


#endif //SOCIALGAMING_STATEVALUE_H
