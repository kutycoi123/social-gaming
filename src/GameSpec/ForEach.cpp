#include "ForEach.h"

using GameSpecification::ForEach;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;
ForEach::ForEach() : BaseRule("foreach"), _element(""){}

ForEach::ForEach(const SpecValue& list, const std::string& element, std::vector<std::string>& rules) : BaseRule("foreach"), 
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

void ForEach::process(){
	//TODO: Add code to process foreach rule
}
