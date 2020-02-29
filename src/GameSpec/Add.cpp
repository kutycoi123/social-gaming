#include "Add.h"

using GameSpecification::Add;
using GameSpecification::SpecValue;
Add::Add() : BaseRule("add"), to(""){}

Add::Add(const std::string& to, const SpecValue& value) : BaseRule("add"), to(to), value(value){}

std::string Add::getTo() const{
    return to;
}
SpecValue Add::getValue() const{
    return value;
}

void Add::process(GameState&){
	//TODO: Add code to process add rule
}
