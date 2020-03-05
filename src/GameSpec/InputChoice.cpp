#include "InputChoice.h"


using GameSpecification::BaseRule;
using GameSpecification::SpecValue;
using GameSpecification::InputChoice;
using GameSpecification::Message;
using json = nlohmann::json;

std::string InputChoice::getTo() const{
	return to;
}
std::string InputChoice::getResult() const{
	return result;
}
std::optional<double> InputChoice::getTimeout() const{
	return timeout;
}
Message InputChoice::getPrompt() const{
	return prompt;
}
	
SpecValue InputChoice::getChoices() const{
	return choices;
}	

void InputChoice::process(GameState& gameState){
	//TODO: add logic for this rule
}

void InputChoice::parseRule(const json &ruleJson){
	try{
		to = ruleJson.at("to").get<std::string>();
		result = ruleJson.at("result").get<std::string>();
		if(ruleJson.find("timeout") != ruleJson.end())
			timeout = std::optional<double>{ruleJson.at("timeout").get<double>()};
		json choices = ruleJson.at("choices");
		if(choices.is_string()){
			this->choices.value = choices.get<std::string>();
		}else{
			this->choices.value = choices.get<std::vector<std::string>>();
		}
		prompt.parseRule(ruleJson.at("prompt"));
	}catch(json::exception &e){
		std::cout << e.what() << "\n";
	}
}

