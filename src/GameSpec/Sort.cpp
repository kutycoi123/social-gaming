#include "Sort.h"

using GameSpecification::Sort;

Sort::Sort(): BaseRule("sort"), _list(""), _key("") {}

Sort::Sort(const std::string& list, const std::string& key): _list(list), _key(key){}

std::string Sort::getList() const{
    return _list;
}

std::string Sort::getKey() const{
    return _key;
}

void Sort::process(){

}