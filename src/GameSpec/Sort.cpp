#include "Sort.h"

using GameSpecification::Sort;
using json = nlohmann::json;
Sort::Sort(): BaseRule("sort"), list(""), key("") {}

Sort::Sort(const std::string& list, const std::string& key): list(list), key(key){}

std::string Sort::getList() const{
    return list;
}

std::string Sort::getKey() const{
    if(key.has_value())
        return key.value();
    return "";
}

void Sort::process(GameState& gameState){

}

void Sort::parseRule(const json &ruleJson){
    try{
        list = ruleJson.at("list").get<std::string>();
        if(ruleJson.find("key") != ruleJson.end())
            key = std::optional<std::string>{ruleJson.at("key").get<std::string>()};
    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}