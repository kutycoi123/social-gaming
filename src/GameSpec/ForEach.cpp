#include "ForEach.h"

using GameSpecification::ForEach;
//using GameSpecification::SpecValue;
//using GameSpecification::BaseRule;
using json = nlohmann::json;

ForEach::ForEach(const std::list<std::shared_ptr<BaseRule>>& childRules, const SpecValue& list, const std::string& element) : 
	BaseRule(childRules), 
	list(list), 
	element(element) 
	{}

//TODO: Add code to process foreach rule
void ForEach::process(GameState& gameState){}


/*
void ForEach::parseRule(const json &ruleJson) {
	
    try{

        auto el = ruleJson.find("element");
        if (el != ruleJson.end()) {
            element = el.value().get<std::string>();
        }
        auto listEL = ruleJson.find("list");
        if(listEL != ruleJson.end()) {
            auto listJson = listEL.value();
            if (listJson.is_array()) {
                list.value = listJson.get < std::vector < std::string >> ();
            } else {
                list.value = listJson.get<std::string>();
            }
        }

        auto subRules = ruleJson.find("rules");
        if( subRules != ruleJson.end() ) {
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
                            continue;
                    }
                }
                //TODO: investigate CRASHES program.
                baseRulePtr->setParentPtr(std::shared_ptr<BaseRule>(this));
                this->subRules.push_back(baseRulePtr);
            }


        }
        //TODO: investigate setNext-- CRASHES Program
		//Set next pointer for each subRule

//		for(auto it = this->subRules.begin(); it != this->subRules.end() - 1; ++it){
//			(*it)->setNextPtr(*(it+1));
//		}
//		//Set next pointer for the last rule to point back to the parent Rule
// 		(*this->subRules.rbegin())->setNextPtr((this->getPtr()));
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
	
}

*/