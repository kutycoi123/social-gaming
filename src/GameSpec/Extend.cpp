#include "Extend.h"

using GameSpecification::BaseRule;
using GameSpecification::Extend;
using GameSpecification::SpecValue;
Extend::Extend() : BaseRule("extend"), _target(""){}

Extend::Extend(const std::string& target, const SpecValue& list) : BaseRule("extend"), _target(target), _list(list){}

std::string Extend::getTarget() const{
    return _target;
}

SpecValue Extend::getList() const{
    return _list;
}

void Extend::process(){
	//TODO: Add code to process extend rule
}
