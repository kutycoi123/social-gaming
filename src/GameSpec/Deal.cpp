#include "Deal.h"

using GameSpecification::Deal;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;

Deal::Deal() : BaseRule("deal"), _from(""), _count(0){}

Deal::Deal(const std::string& from, const SpecValue& to, const int count) : BaseRule("deal"), _from(from), _to(to), _count(count){}

std::string Deal::getFrom() const{
    return _from;
}

SpecValue Deal::getTo() const{
    return _to;
}

int Deal::getCount() const{
    return _count;
}

void Deal::process() {
	//TODO: Add code to process deal rule
}

