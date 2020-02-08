#include "Extend.h"

Extend::Extend() : Rule("extend"), _target(""){}

Extend::Extend(const std::string& target, const SpecValue& list) : Rule("extend"), _target(target), _list(list){}

std::string Extend::getTarget() const{
    return _target;
}

SpecValue Extend::getList() const{
    return _list;
}

void Extend::setTarget(const std::string& target){
    _target = target;
}

void Extend::setList(const SpecValue& list){
    _list = list;
}