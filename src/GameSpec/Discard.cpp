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

void Discard::setFrom(const std::string& from){
    _from = from;
}

void Discard::setCount(const int count){
    _count = count;
}
