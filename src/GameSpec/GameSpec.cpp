#include "GameSpec.h"
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

		if(ruleType == RuleTags::ForEach){
			//get params and setup rule with the child list, assign to result
		}
		else{
			//something horrible happened
			assert(false);
		}

		//make last child point back to us
	}
	else{
		//these rules should not have childs, so their processing is quite simple

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


