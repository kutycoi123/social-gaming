#include "Reverse.h"
#include <boost/range/algorithm/reverse.hpp>
#include <iterator>
#include <algorithm>

using GameSpecification::Reverse;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Reverse::Reverse() : BaseRule(RuleType::ReverseType), list(""){}

Reverse::Reverse(const std::string& list) : BaseRule(RuleType::ReverseType), list(list) {}

std::string Reverse::getList() const{
    return list;
}

void Reverse::process(GameState& gameState) {
    auto variables = gameState.getVariable(list);
    if(auto retrievedValue = variables->lock()){
        auto value = boost::apply_visitor(Visit_Type(), retrievedValue.get()->value);
        auto varList = value.map;
        auto getList = varList.find(list);
        auto val = boost::apply_visitor(Visit_Type(), getList->second);
        boost::range::reverse(val.vect);
    }
}

void Reverse::parseRule(const nlohmann::json& json){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}