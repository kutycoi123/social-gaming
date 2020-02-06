#include "include/rule.h"

Rule::Rule(const std::string& rule) : _rule(rule){
}

std::string Rule::getRule() const{
    return _rule;
}

void Rule::setRule(const std::string& rule){
    _rule = rule;
}
