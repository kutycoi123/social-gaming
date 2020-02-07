#include "Inparallel.h"

Inparallel::Inparallel(std::vector<std::string> rules) : Rule("inparallel"), _rules(rules) {}

std::vector<std::string> Inparallel::getRules() const{
    return _rules;
}
void Inparallel::setRules(const std::vector<std::string>& rules){
    _rules = rules;
}