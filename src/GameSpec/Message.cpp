#include "Message.h"
#include "MessageVisitor.h"


using GameSpecification::Message;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;
using json = nlohmann::json;

Message::Message() : BaseRule(RuleType::MessageType){}

Message::Message(const json &ruleJson) : BaseRule(RuleType::MessageType){
	parseRule(ruleJson);
}

SpecValue Message::getTo() const{
	return to;
}

std::string Message::getValue() const{
	return messValue;
}

void Message::process(GameState& gameState){
    auto variables = gameState.getVariable(messValue);
    if (auto retrievedValue = variables->lock()) {
        MessageVisitor visitor;
        retrievedValue->accept(visitor);
    }}

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
		//TODO: Handle exception more properly
		std::cout << e.what() << "\n";
	}
}
