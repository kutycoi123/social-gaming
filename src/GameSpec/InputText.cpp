#include "InputText.h"

using GameSpecification::InputText;
using json = nlohmann::json;

InputText::InputText(): 
        BaseRule(RuleType::InputTextType), user(NULL), prompt(""), result(""), timeout(0){}

InputText::InputText(const std::string& user, const std::string& prompt, const std::string& result, const double timeout): 
    BaseRule(RuleType::InputTextType), user(user), prompt(prompt), result(result), timeout(timeout){}

std::string InputText::getUser() const{
    return user;
}

std::string InputText::getPrompt() const{
    return prompt;
}

std::string InputText::getResult() const{
    return result;
}

double InputText::getTimeOut() const{
    return timeout;
}

void InputText::process(GameState& gameState){
       
}

void InputText::parseRule(const json &ruleJson){
    try{
        user = ruleJson.at("to").get<std::string>();
        prompt = ruleJson.at("prompt").get<std::string>();
        result = ruleJson.at("result").get<std::string>();
        if(ruleJson.find("timeout") != ruleJson.end())
            timeout = ruleJson.at("timeout").get<double>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}