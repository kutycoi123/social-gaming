#include "Parallelfor.h"

using GameSpecification::Parallelfor;
using GameSpecification::ControlStructRule;

Parallelfor::Parallelfor() : ControlStructRule("parallelfor") {}
Parallelfor::Parallelfor(std::vector<std::string> list, const std::string& element) : ControlStructRule("parallelfor"), 
    _list(list), _element(element){}

std::vector<std::string> Parallelfor::getList() const{
    return _list;
}

std::string Parallelfor::getElement() const{
    return _element;
}

void Parallelfor::process(){
	//TODO: Add code to process Parallelfor
}
