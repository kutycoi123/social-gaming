#include "Parallelfor.h"

using GameSpecification::Parallelfor;
using GameSpecification::ControlStructRule;

Parallelfor::Parallelfor() : ControlStructRule("parallelfor") {}
Parallelfor::Parallelfor(std::vector<std::string> list, const std::string& element) : ControlStructRule("parallelfor"), 
    list(list), element(element){}

std::vector<std::string> Parallelfor::getList() const{
    return list;
}

std::string Parallelfor::getElement() const{
    return element;
}

void Parallelfor::process(GameState& gameState){
	//TODO: Add code to process Parallelfor
}

void Parallelfor::parseRule(const nlohmann::json &json){
    //TODO: Add parsing logic
}