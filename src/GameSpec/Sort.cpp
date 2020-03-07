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
    auto variables = gameState.getVariables(list);
    auto test = boost::get<std::unordered_map<std::string, std::string>>(variables.value().get().value);
    auto varList = test.find(list);
    std::sort(varList->second.begin(), varList->second.end());

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