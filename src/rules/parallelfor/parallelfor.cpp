#include "include/parallelfor.h"

Parallelfor::Parallelfor(std::vector<std::string> list, const std::string& element, std::vector<std::string> rules) : Rule("parallelfor"){
    _list = list;
    _element = element;
    _rules = rules;
}

std::vector<std::string> Parallelfor::getList() const{
    return _list;
}

std::string Parallelfor::getElement() const{
    return _element;
}

std::vector<std::string> Parallelfor::getRules() const{
    return _rules;
}

void Parallelfor::setList(const std::vector<std::string>& list){
    _list = list;
}

void Parallelfor::setElement(const std::string& element){
    _element = element;
}

void Parallelfor::setRules(const std::vector<std::string>& rules){
    _rules = rules;
}