#include "Message.h"


using GameSpecification::Message;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;
using json = nlohmann::json;
SpecValue Message::getTo() const{
	return to;
}

std::string Message::getValue() const{
	return messValue;
}

void Message::process(GameState& gameState){
	//TODO: Add code to process message rule
}

void Message::parseRule(const json &ruleJson){
	try{
		messValue = ruleJson.at("value").get<std::string>();
		json to = ruleJson.at("to");
		if(to.is_string()){
			this->to.value = to.get<std::string>();
		}else{
			this->to.value = to.get<std::vector<std::string>>();
		}
	}catch(json::exception& e){
		std::cout << e.what() << "\n";
	}
}
