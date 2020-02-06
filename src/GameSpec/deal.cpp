#include "include/deal.h"

Deal::Deal() : Rule("deal"), _from(""), _to(NULL), _count(0){}

Deal::Deal(cosnt std::string& from, const SpecValue& to, const int count) : Rule("deal"), _from(from), _to(to), _count(cont){}

std::string Deal::getFrom() const{
    return _from;
}

SpecValue Deal::getTo() const{
    return _to;
}

int Deal::getCount() const{
    return count;
}

void Deal::setFrom(const std::string& from){
    _from = from;
}

void Deal::setTo(const SpecValue& to){
    _to = to;
}

void Deal::setCount(const int count){
    _count  = count;
}