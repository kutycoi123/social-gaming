#include "Add.h"

using GameSpecification::Add;
using GameSpecification::SpecValue;
Add::Add() : BaseRule("add"), _to(""){}

Add::Add(const std::string& to, const SpecValue& value) : BaseRule("add"), _to(to), _value(value){}

std::string Add::getTo() const{
    return _to;
}
SpecValue Add::getValue() const{
    return _value;
}

void Add::setTo(const std::string& to){
    _to = to;
}

void Add::setValue(const SpecValue& value){
    _value = value;
}
