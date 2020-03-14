#include "Case.h"

using GameSpecification::Case;

Case::Case(){}

Case::Case(const std::string& value, const std::vector<BaseRule>& rules): value(value), rules(rules){}

std::vector<BaseRule> Case::getRules(){
    return rules;
}

std::string Case::getValue(){
    return value;
}