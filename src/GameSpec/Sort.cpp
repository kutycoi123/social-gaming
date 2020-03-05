#include "Sort.h"

using GameSpecification::Sort;

Sort::Sort(): BaseRule("sort"), list(""), key("") {}

Sort::Sort(const std::string& list, const std::string& key): list(list), key(key){}

std::string Sort::getList() const{
    return list;
}

std::string Sort::getKey() const{
    return key;
}

void Sort::process(GameState& gameState){

}

void Sort::parseRule(const nlohmann::json &json){
    //TODO: Add parsing logic
}