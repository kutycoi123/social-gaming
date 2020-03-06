#include "GlobalMessage.h"

using GameSpecification::GlobalMessage;
using json = nlohmann::json;
GlobalMessage::GlobalMessage(): BaseRule(RuleType::GlobalMessageType), value(""){}

GlobalMessage::GlobalMessage(const std::string& value)
            : BaseRule(RuleType::GlobalMessageType), value(value){}

std::string GlobalMessage::getValue() const{
    return value;
}

void GlobalMessage::process(GameState& gameState){
    
}

void GlobalMessage::parseRule(const json &ruleJson){
    try{
       value = ruleJson.at("value").get<std::string>(); 
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}