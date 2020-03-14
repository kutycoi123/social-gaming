#include "Extend.h"

using GameSpecification::BaseRule;
using GameSpecification::Extend;
using GameSpecification::SpecValue;
using json = nlohmann::json;
Extend::Extend() : BaseRule(RuleType::ExtendType), target(""){}

Extend::Extend(const std::string& target, const SpecValue& list) : BaseRule(RuleType::ExtendType), target(target), list(list){}

std::string Extend::getTarget() const{
    return target;
}

SpecValue Extend::getList() const{
    return list;
}

void Extend::process(GameState& gameState){
	//TODO: Add code to process extend rule
}

void Extend::parseRule(const json& ruleJson){
    try{
        target = ruleJson.at("target").get<std::string>();
        json list = ruleJson.at("list");
		if(list.is_string()){
			this->list.value = list.get<std::string>();
		}else{
			this->list.value = list.get<std::vector<std::string>>();
		}
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}