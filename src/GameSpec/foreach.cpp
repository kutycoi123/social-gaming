#include "Foreach.h"

ForEach::ForEach() : Rule("foreach"), _element(""){}

ForEach::ForEach(const SpecValue& list, const std::string& element, std::vector<std::string>& rules) : Rule("foreach"), 
    _list(list), _element(element), _rules(rules){}

SpecValue ForEach::getList() const{
    return _list;
}

std::string ForEach::getElement() const{
    return _element;
}

std::vector<std::string> ForEach::getRules() const{
    return _rules;
}

void ForEach::setList(const SpecValue& list){
    _list = list;
}

void ForEach::setElement(const std::string& element){
    _element = element;
}

void ForEach::setRules(const std::vector<std::string>& rules){
    _rules = rules;
}