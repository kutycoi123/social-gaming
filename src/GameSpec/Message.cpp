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
    auto variables = gameState.getVariable(messValue);
    if (auto retrievedValue = variables->lock()) {
        auto val = boost::apply_visitor(Visit_Type(), retrievedValue.get()->value);

//        if(val.i){
//            //add message to the game
//        }
//        if(val.str.size()>0){
//            //add message to the game
//        }
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
