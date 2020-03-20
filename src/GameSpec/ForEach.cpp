#include "ForEach.h"

using GameSpecification::ForEach;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;
using json = nlohmann::json;

ForEach::ForEach() : BaseRule(RuleType::ForEachType), element(""){}

ForEach::ForEach(const json& ruleJson) : BaseRule(RuleType::ForEachType){
	parseRule(ruleJson);
}

SpecValue ForEach::getList() const{
    return list;
}

std::string ForEach::getElement() const{
    return element;
}



void ForEach::process(GameState& gameState){
	//TODO: Add code to process foreach rule
}

void ForEach::parseRule(const json &ruleJson){
    try{
		element = ruleJson.at("element").get<std::string>();
		auto listJson = ruleJson.at("list");
		if(listJson.is_array()){
			list.value = listJson.get<std::vector<std::string>>();
		}else{
			list.value = listJson.get<std::string>();
		}
		auto subRulesJson = ruleJson.at("rules");
		for(auto& it : subRulesJson.items()){
			auto rule = it.value();
			auto ruleType = stringToRuleType.at(rule.at("rule").get<std::string>());
			auto baseRulePtr = getRulePtrFromRuleType(ruleType, rule);
			if(!baseRulePtr){
				switch(ruleType){
					case RuleType::ForEachType:
						baseRulePtr = std::shared_ptr<BaseRule>(new ForEach(rule));
						break;
					case RuleType::InparallelType:
						baseRulePtr = std::shared_ptr<BaseRule>(new Inparallel(rule));
						break;
					case RuleType::LoopType:
						baseRulePtr = std::shared_ptr<BaseRule>(new Loop(rule));
						break;
					case RuleType::ParallelforType:
						baseRulePtr = std::shared_ptr<BaseRule>(new Parallelfor(rule));
						break;
					default:
						assert(false);
				}
			}
			baseRulePtr->setParentPtr(this->getPtr());
			this->subRules.push_back(baseRulePtr);
		}
		//Set next pointer for each subRule
		for(auto it = subRules.begin(); it != subRules.end() - 1; ++it){
			(*it)->setNextPtr(*(it+1));
		}
		//Set next pointer for the last rule to point back to the parent Rule
		(*subRules.rbegin())->setNextPtr((this->getPtr()));	
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}
