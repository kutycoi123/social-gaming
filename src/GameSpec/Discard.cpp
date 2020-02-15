#include "Discard.h"
using GameSpecification::Discard;
using GameSpecification::BaseRule;
Discard::Discard() : BaseRule("discard"), _from(""), _count(0){}

Discard::Discard(const std::string& from, const int count) : BaseRule("discard"), _from(from), _count(count){}

std::string Discard::getFrom() const{
    return _from;
}

int Discard::getCount() const{
    return _count;
}

void Discard::process() {
	//TODO: Add code to process discard rule
}
