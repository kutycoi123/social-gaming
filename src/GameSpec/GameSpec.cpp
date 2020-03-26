#include "GameSpec.h"
#include <iterator>
#include <fstream>

using GameSpecification::GameSpec;

namespace SpecTags{
	std::string RULE_LIST = "rules";
	std::string RULE_NAME = "rule";
}

namespace RuleTags{
	std::string Add = "add"; 
	std::string Deal = "deal"; 
	std::string Discard = "discard"; 
	std::string Extend = "extend"; 
	std::string ForEach = "foreach"; //contains child rules
	std::string GlobalMessage = "global-message"; 
	std::string Inparallel = "inparallel"; //contains child rules
	std::string InputChoice = "input-choice"; 
	std::string InputText = "input-text";
	std::string InputVote = "input-vote";
	std::string Loop = "loop"; //contains child rules
	std::string Message = "message"; //missing cmake target
	std::string Parallelfor = "parallelfor"; //contains child rules
	std::string Reverse = "reverse"; 
	std::string Scores = "scores"; 
	std::string Shuffle = "shuffle"; 
	std::string Sort = "sort"; 
	std::string Switch = "switch"; //contains child rules //missing cmake target
	std::string Timer = "timer"; //contains child rules
	std::string When = "when"; //contains child rules //missing cmake target
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
		auto subRules = currentRuleJson
			.at(SpecTags::RULE_LIST);
		
		//recursively parse every rule in the array of rules
		for (auto& subRule : subRules){
			auto singleChildrule = recursivelyParseSpec(subRule);
			childRules.push_back(singleChildrule);
		} 

		//configure make each (n)th childRule point to (n+1)th childRule, ignore last one
		for(auto it = childRules.begin(); it != childRules.end(); ++it){
			if(it == childRules.end()) break;
			(*it)->addNextPtr(*(std::next(it, 1)));
		}

		if(ruleType == RuleTags::ForEach){
			//get params and setup rule with the child list, assign to result
		}
		else if(ruleType == RuleTags::Inparallel){
			//get params and setup rule with the child list, assign to result
		}
		else{
			//something horrible happened
			assert(false);
		}

		//make last child point back to us
		auto lastChild = childRules.rbegin();
		if(lastChild != childRules.rend()){
			(*lastChild)->addNextPtr(result);
		}		
	}
	else{
		//these rules should not have childs, so their processing is quite simple
		//these are the non-recursive parts

		if(ruleType == RuleTags::Add){
			//setup rule, assign to result
		} 
		else if(ruleType == RuleTags::Deal){
			//setup rule, assign to result
		}
		else{
			//something horrible happened
			assert(false);
		}

	}

	return result;
}


