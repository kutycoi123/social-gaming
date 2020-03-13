#ifndef SOCIALGAMING_STATEVALUE_H
#define SOCIALGAMING_STATEVALUE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <boost/variant.hpp>

class StateValue {
public:
    enum ValueType {
        BOOLEAN,
        INT,
        STRING,
        DOUBLE
    };
    explicit StateValue(int);
    explicit StateValue(double);
    explicit StateValue(bool);
    explicit StateValue(const std::string&);
    [[nodiscard]] ValueType getType() const;
    boost::variant<std::string, int,
            bool, double>& getValue();
private:
    boost::variant<std::string, int,
            bool, double> value;
    ValueType valueType;
};

#endif //SOCIALGAMING_STATEVALUE_H
