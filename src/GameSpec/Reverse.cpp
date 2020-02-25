#include "Reverse.h"

using GameSpecification::Reverse;
using GameSpecification::BaseRule;
Reverse::Reverse() : BaseRule("reverse"), list(""){}

Reverse::Reverse(const std::string& list) : BaseRule("reverse"), list(list) {}

std::string Reverse::getList() const{
    return list;
}

void Reverse::process() {
	//TODO: Add code to process reverse rule
}

