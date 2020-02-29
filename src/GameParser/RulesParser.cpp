#include <list>
#include <nlohmann/json.hpp>
#include <cassert>
#include <fstream>
#include <string>
#include "BaseRule.h"
#include "Add.h"
#include "Deal.h"
#include "GlobalMessage.h"
#include "IncludeChoice.h"
#include "IncludeText.h"
#include "InputVote.h"
#include "Message.h"
#include "Reverse.h"
#include "Scores.h"
#include "Sort.h"
#include <iostream>

std::vector<GameSpecification::BaseRule> jsonToGameSpec (nlohmann::json jsonRules){
    std::vector<GameSpecification::BaseRule> rules;
    for (auto& element : jsonRules){
        if(element["rule"] == "foreach"){
            
        }
        else if (element["rule"] == "loop"){

        }
        else if (element["rule"] == "inparallel"){

        }
        else if (element["rule"] == "parallelfor"){

        }
        else if (element["rule"] == "timer"){

        }
        else if (element["rule"] == "add"){
            std::string to = element["to"];
            SpecValue value = element["value"];
            GameSpecification::Add add {to, value};
            rules.push_back(add);
        }
        else if(element["rule"] == "deal"){
            std::string from = element["from"];
            SpecValue to = element["to"];
            int count = element["count"];
            GameSpecification::Deal deal{from, to, count};
            rules.push_back(deal);
        }
        else if(element["rule"] == "discard"){
            std::string from = element["from"];
            int count = element["count"];
            GameSpecification::Discard discard{from, count};
            rules.push_back(discard);
        }
        else if(element["rule"] == "extend"){
            std::string target = element["target"];
            SpecValue list = element["list"];
            GameSpecification::Extend extend{target, list};
            rules.add(extend);
        }
        else if(element["rule"] == "global-message"){
            std::string value = element["value"];
            GameSpecification::GlobalMessage globalMessage {value};
            rules.push_back(globalMessage);
        }
        else if(element["rule"] == "input-choice"){
                std::string to = element["to"];
    			Message prompt = element["prompt"]; 
    			SpecValue choices = element["choices"];
    			std::string result = element["result"];
    			std::string timeout = element["timeout"];
                GameSpecification::InputChoice inputChoice {to, prompt, choices, result, timeout};
                rules.push_back(inputChoice);
        }
        else if(element["rule"] == "input-text"){
            std::string user = element["to"];
            std::string prompt = element["prompt"];
            std::string result = element["result"];
            double timeout = element["timeout"];
            GameSpecification::InputText inputText {user, prompt, result, timeout};
            rules.push_back(inputText);

        }
        else if(element["rule"] == "input-vote"){
            std::string user = element["to"];
            std::string prompt = element["prompt"];
            std::string choices = element["choices"];
            std::string result = element["result"];
            double timeout = element["timeout"];
            GameSpecification::InputVote inputVote {user, prompt, choices, result, timeout};
            rules.push_back(inputVote);
        }
        else if(element["rule"] == "message"){
            SpecValue to = element["to"];
			std::string	messValue = element["value"];
            GameSpecification::Message message{to, value};
            rules.push_back(message);
        }
        else if(element["rule"] == "reverse"){
            std::string list = element["list"];
            GameSpecification::Reverse reverse{list};
            rules.push_back(reverse);
        }
        else if(element["rule"] == "scores"){
            double score = element["score"];
            bool ascending = element["ascending"];
            GameSpecification::Scores scores{score, ascending};
            rules.push_back(scores);
        }
        else if(element["rule"] == "shuffle"){

        }
        else if(element["rule"] == "sort"){
            std::string list = element["sort"];
            std::string key = element["key"];
            GameSpecification::Sort sort{list, key};
            rules.push_back(sort);
        }
        return rules;
    }
}
