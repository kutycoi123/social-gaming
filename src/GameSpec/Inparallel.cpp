#include "Inparallel.h"

using GameSpecification::Inparallel;
using GameSpecification::BaseRule;
Inparallel::Inparallel(std::vector<std::string> rules) : BaseRule("inparallel"), _rules(rules) {}

std::vector<std::string> Inparallel::getRules() const{
    return _rules;
}
void Inparallel::setRules(const std::vector<std::string>& rules){
    _rules = rules;
}
