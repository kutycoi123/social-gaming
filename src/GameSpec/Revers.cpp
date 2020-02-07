#include "Reverse.h"

Reverse::Reverse() : Rule("reverse"), _list(""){}

Reverse::Reverse(const std::string& list) : Rule("reverse"), _list(list) {}

std::string Reverse::getList() const{
    return _list;
}

void Reverse::setList(const std::string& list){
    _list = list;
}

