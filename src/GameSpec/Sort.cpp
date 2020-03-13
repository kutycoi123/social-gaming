#include "Sort.h"

using GameSpecification::Sort;
using json = nlohmann::json;

Sort::Sort(): BaseRule(RuleType::SortType), list(""), key("") {}

Sort::Sort(const std::string& list, const std::string& key)
    : BaseRule(RuleType::SortType), list(list), key(key){}

std::string Sort::getList() const{
    return list;
}

std::optional<std::string> Sort::getKey() const{
    return key;
}

void Sort::process(GameState& gameState){
    auto variables = gameState.getVariable(list);
    if (auto retrievedValue = variables->lock()) {
        auto value = boost::apply_visitor(Visit_Type(), retrievedValue->value);
        auto varList = value.map;
        auto getList = varList.find(list);
        auto val = boost::apply_visitor(Visit_Type(), getList->second);
        std::sort(val.str.begin(),val.str.end());
    }
}

void Sort::parseRule(const json &ruleJson){
    try{
        list = ruleJson.at("list").get<std::string>();
        if(ruleJson.find("key") != ruleJson.end())
            key = std::optional<std::string>{ruleJson.at("key").get<std::string>()};
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}