#include "GameSpec.h"
#include <iterator>
#include <algorithm>
#include <fstream>

using GameSpecification::GameSpec;
using json = nlohmann::json;





namespace SpecTags{
    std::string RULE_LIST = "rules";
    std::string RULE_NAME = "rule";
    std::string LIST = "list";
    std::string ELEMENT = "element";
    std::string FROM = "from";
    std::string TO = "to";
    std::string PROMPT = "prompt";
    std::string TARGET = "target";
    std::string CHOICES = "choices";
    std::string VALUE = "value";
    std::string TIMEOUT = "timeout";
    std::string RESULT = "result";
    std::string TRACK = "track";
    std::string COUNT = "count";
    std::string SCORE = "score";
    std::string ASCENDING = "ascending";
    std::string DURATION = "duration";
    std::string MODE = "mode";

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

            auto element = currentRuleJson.at(SpecTags::ELEMENT).get<std::string>();
            auto listJson = currentRuleJson.at(SpecTags::LIST);
            std::unique_ptr<StateValue> listPtr;
            if(listJson.is_string()){
                listPtr = std::unique_ptr<StateValue>(new StateValueString(listJson.get<std::string>()));
            }else if(listJson.is_array()){
                createStateList(listJson,listPtr);

            }else{
                std::cout << "Unhandled ForEach list type\n";
                assert(false);
            }
            result = std::shared_ptr<BaseRule>(new ForEach(childRules, listPtr, element));


		}
		else if(ruleType == RuleTags::Inparallel){
			//get params and setup rule with the child list, assign to result
		}
		else if(ruleType == RuleTags::Parallelfor){
            //get params and setup rule with the child list, assign to result
        }
        else if(ruleType == RuleTags::Timer){

            double duration = currentRuleJson.at(SpecTags::DURATION).get<std::double_t>();
            std::string mode = currentRuleJson.at(SpecTags::MODE).get<std::string>();
            bool flag = (mode == SpecTags::TRACK);
            result = std::shared_ptr<BaseRule>(new Timer(childRules, duration, mode,flag));
            //get params and setup rule with the child list, assign to result
        }
        else if(ruleType == RuleTags::Loop){

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
        //1 rules field. only .

		if(ruleType == RuleTags::Add){

            std::string to = currentRuleJson.at( SpecTags::TO);
            std::string value = currentRuleJson.at(SpecTags::VALUE);
            std::unique_ptr<StateValue> ptr = std::make_unique<StateValueString>(value);
            auto toAdd = std::make_shared<GameSpecification::Add>(GameSpecification::Add(to, ptr));
            addRule(toAdd);

		}
		else if(ruleType == RuleTags::Discard){

            std::string from = currentRuleJson.at(SpecTags::FROM).get<std::string>();
            int count = currentRuleJson.at(SpecTags::COUNT).get<int>();
            result = std::shared_ptr<BaseRule>(new Discard(from, count));

        }
        else if(ruleType == RuleTags::Scores){

            int score = currentRuleJson.at(SpecTags::SCORE).get<int>();
            bool ascending = currentRuleJson.at(SpecTags::ASCENDING).get<bool>();
            result = std::shared_ptr<BaseRule>(new Scores(score, ascending));

        }

		else if(ruleType == RuleTags::Deal) {

            std::unique_ptr<StateValue> stateValuePointer = nullptr;
            std::vector<std::shared_ptr<StateValue>> listInRule;
            std::string from = currentRuleJson.at( SpecTags::FROM);
            auto to = currentRuleJson.at(SpecTags::TO);
            createStateList(to,stateValuePointer);//changes statevaluePointer to stateList with populated List
            int count = currentRuleJson.at(SpecTags::COUNT);
            auto toAdd = std::make_shared<GameSpecification::Deal>(GameSpecification::Deal(from, stateValuePointer,count));
            addRule(toAdd);
            result = toAdd;

            //setup rule, assign to result
        } else if(ruleType == RuleTags::Extend){
            std::unique_ptr<StateValue> stateValuePointer = nullptr;
            std::string target = currentRuleJson.at( SpecTags::TARGET);
            auto list = currentRuleJson.at( SpecTags::LIST);

            if(list.is_array()) {
                std::vector<std::shared_ptr<StateValue>> listValue;
                createStateList(list,stateValuePointer);//ptr is reference
            } else if(list.is_string()) {
                stateValuePointer = std::make_unique<StateValueString>(list);
            }

            if(stateValuePointer) {
                auto toAdd = std::make_shared<GameSpecification::Extend>(GameSpecification::Extend(target, stateValuePointer));
                addRule(toAdd);
                result = toAdd;
            }

        } else if(ruleType == RuleTags:: GlobalMessage){

            std::string value = currentRuleJson.at( SpecTags::VALUE);
            auto toAdd = std::make_shared<GameSpecification::GlobalMessage>(GameSpecification::GlobalMessage(value));
            addRule(toAdd);
            result = toAdd;

        } else if(ruleType == RuleTags::InputChoice){
		    
            std::unique_ptr<StateValue> stateValuePointer ;
            std::string to = currentRuleJson.at( SpecTags::TO).get<std::string>();
            std::string prompt = currentRuleJson.at( SpecTags::PROMPT).get<std::string>();
            std::string result = currentRuleJson.at( SpecTags::RESULT).get<std::string>();
            double timeout = currentRuleJson.at( SpecTags::TIMEOUT).get<std::double_t >();

            auto choices = currentRuleJson.at( SpecTags::CHOICES);

            if(choices.is_array()) {
                std::vector<std::shared_ptr<StateValue>> listValue;
                createStateList(choices,stateValuePointer);//ptr is reference
            } else if(choices.is_string()) {
                stateValuePointer = std::make_unique<StateValueString>(choices);
            }
            auto toAdd = std::make_shared<GameSpecification::InputChoice>(GameSpecification::InputChoice(to,prompt,stateValuePointer,result,timeout));
            addRule(toAdd);


        } else if(ruleType == RuleTags::InputText){

        } else if(ruleType == RuleTags::InputVote){

        } else if(ruleType == RuleTags::Message){

        } else if(ruleType == RuleTags::Reverse){

        } else if(ruleType == RuleTags::Shuffle){

        } else if(ruleType == RuleTags::Sort){

        } else if(ruleType == RuleTags::Switch){

        } else if(ruleType == RuleTags::When){

        }


    	else{
			//something horrible happened
			assert(false);
		}


	}

	return result;
}

void GameSpec::createStateList(const json list,std::unique_ptr<StateValue> &ptr) {//TODO: move this inside StateList.
    std::vector<std::shared_ptr<StateValue>> listValue;
    std::transform(list.begin(), list.end(),
       std::back_inserter(listValue),
       [](const json& listElem){
                       if(listElem.is_number()){
                           int value = listElem.get<int>();
                           return std::shared_ptr<StateValue>(new StateValueNumber(value));
                       }else if(listElem.is_string()){
                           std::string value = listElem.get<std::string>();
                           return std::shared_ptr<StateValue>(new StateValueString(value));
                       }else{
                           std::cout << "Unhandled list element type\n";
                           assert(false);
                       }
                   });

    ptr = std::make_unique<StateValueList>(listValue);
}


