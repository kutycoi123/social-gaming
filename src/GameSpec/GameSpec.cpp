#include "GameSpec.h"
#include <fstream>

using GameSpecification::GameSpec;

namespace SpecTags{
	std::string RULE_LIST = "rules";
	std::string RULE_NAME = "rule";
}

namespace RuleTags{
	const std::string Add = "add";
    const std::string Deal = "deal";
    const std::string Discard = "discard";
    const std::string Extend = "extend";
    const std::string ForEach = "foreach"; //contains child rules
    const std::string GlobalMessage = "global-message";
    const std::string Inparallel = "inparallel"; //contains child rules
    const std::string InputChoice = "input-choice";
    const std::string InputText = "input-text";
    const std::string InputVote = "input-vote";
    const std::string Loop = "loop"; //contains child rules
    const std::string Message = "message"; //missing cmake target
    const std::string Parallelfor = "parallelfor"; //contains child rules
    const std::string Reverse = "reverse";
    const std::string Scores = "scores";
    const std::string Shuffle = "shuffle";
    const std::string Sort = "sort";
    const std::string Switch = "switch"; //contains child rules //missing cmake target
    const std::string Timer = "timer"; //contains child rules
    const std::string When = "when"; //contains child rules //missing cmake target
}

GameSpec::GameSpec(const nlohmann::json& fullFileJson) : rules({}){
	nlohmann::json rulesJson = readSpec(fullFileJson);
	processSpec(rulesJson);
}


std::list<std::shared_ptr<BaseRule>> GameSpec::getRules() const{
	return rules;
}

void GameSpec::addRule(std::shared_ptr<BaseRule> rule){
	rules.push_back(rule);
}

nlohmann::json GameSpec::readSpec(const nlohmann::json& fullFileJson){
	return fullFileJson.at(SpecTags::RULE_LIST);
}

void GameSpec::processSpec(const nlohmann::json& ruleJson){
	std::vector<nlohmann::json> ruleList = ruleJson.get<std::vector<nlohmann::json>>();

	for(auto& rule : ruleList){
		auto parsedRule = recursivelyParseSpec(rule);
		addRule(parsedRule);
	}
}

std::shared_ptr<BaseRule> GameSpec::recursivelyParseSpec(const nlohmann::json& currentRuleJson){
	std::string ruleType = currentRuleJson
		.at(SpecTags::RULE_NAME)
		.get<std::string>();	

	std::shared_ptr<BaseRule> result;

	if(currentRuleJson.contains(SpecTags::RULE_LIST)){
		//these rules have child rules so we need to do more complex processing
		//this part is the recursive part

		std::list<std::shared_ptr<BaseRule>> childRules {};
		
		//every rule list has an array of rules
		std::list<nlohmann::json> subrules = currentRuleJson
			.at(SpecTags::RULE_LIST)
			.get<std::list<nlohmann::json>>();
		
		//recursively parse every rule in the array of rules
		for (auto& subrule : subrules){
			auto singleChildrule = recursivelyParseSpec(subrule);
			childRules.push_back(singleChildrule);
		} 

		//configure make each (n)th childRule point to (n+1)th childRule, ignore last one

		if(ruleType == RuleTags::ForEach){
			//get params and setup rule with the child list, assign to result
		}
		else if(ruleType == RuleTags::Inparallel){
			//get params and setup rule with the child list, assign to result
		} else if(ruleType == RuleTags::Parallelfor){
            //get params and setup rule with the child list, assign to result
        }
		else{
			//something horrible happened
			assert(false);
		}
		///

		///

		//make last child point back to us
	}
	else{
		//these rules should not have childs, so their processing is quite simple
		//these are the non-recursive parts
        //1 rules field. only .
		if(ruleType == RuleTags::Add){
		    //check each field. crate the right stateValue,
		    //add into the constructor.
		    //
			//setup rule, assign to result

            std::string to = currentRuleJson.at( "to");
            int value = currentRuleJson.at("value");
            std::unique_ptr<StateValue> ptr = std::make_unique<StateValueNumber>(value);
            auto toAdd = std::make_shared<GameSpecification::Add>(GameSpecification::Add(to, ptr));
            addRule(toAdd);

		} else if(ruleType == RuleTags::Deal) {
            std::string to = currentRuleJson.at( "to");
            int value = currentRuleJson.at("value");
            std::unique_ptr<StateValue> ptr = std::make_unique<StateValueNumber>(value);
            auto toAdd = std::make_shared<GameSpecification::Add>(GameSpecification::Add(to, ptr));
            addRule(toAdd);

            //setup rule, assign to result
        } else if(ruleType == RuleTags::Discard){
            std::string from = currentRuleJson.at( "from");
            std::unique_ptr<StateValue> ptr = std::make_unique<StateValueList>(value);
            int value = currentRuleJson.at("to");

		} else if(ruleType == RuleTags::Extend){

        } else if(ruleType == RuleTags:: GlobalMessage){

        } else if(ruleType == RuleTags::GlobalMessage){

        } else if(ruleType == RuleTags::InputChoice){

        } else if(ruleType == RuleTags::InputText){

        } else if(ruleType == RuleTags::InputVote){

        } else if(ruleType == RuleTags::Loop){

        } else if(ruleType == RuleTags::Message){

        } else if(ruleType == RuleTags::Reverse){

        } else if(ruleType == RuleTags::Scores){

        } else if(ruleType == RuleTags::Shuffle){

        } else if(ruleType == RuleTags::Sort){

        }else if(ruleType == RuleTags::Switch){

        }else if(ruleType == RuleTags::Timer){

        }else if(ruleType == RuleTags::When){

        }

		else{
			//something horrible happened
			assert(false);
		}


        Discard


	}

	return result;
}


