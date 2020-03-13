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
        BOOLEAN
    };
    explicit StateValue(const std::string& val);
    explicit StateValue(int val);
    explicit StateValue(double val);
    explicit StateValue(bool val);
    boost::variant<std::string, int,
            bool, double>& getValue();
    ValueType getValueType();
private:
    boost::variant<std::string, int,
            bool, double> value;
    ValueType valueType;
};


#endif //SOCIALGAMING_STATEVALUE_H
