#include "Reverse.h"

using GameSpecification::Reverse;
using GameSpecification::BaseRule;
Reverse::Reverse() : BaseRule("reverse"), _list(""){}

Reverse::Reverse(const std::string& list) : BaseRule("reverse"), _list(list) {}

std::string Reverse::getList() const{
    return _list;
}

void Reverse::process() {
	//TODO: Add code to process reverse rule
}

