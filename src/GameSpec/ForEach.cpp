#include "ForEach.h"

using GameSpecification::ForEach;
using GameSpecification::SpecValue;
using GameSpecification::ControlStructRule;
ForEach::ForEach() : ControlStructRule("foreach"), _element(""){}

ForEach::ForEach(const SpecValue& list, const std::string& element) : ControlStructRule("foreach"), 
    _list(list), _element(element){}

SpecValue ForEach::getList() const{
    return _list;
}

std::string ForEach::getElement() const{
    return _element;
}



void ForEach::process(){
	//TODO: Add code to process foreach rule
}
