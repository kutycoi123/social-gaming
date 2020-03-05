#include "InputText.h"

using GameSpecification::InputText;
using json = nlohmann::json;
InputText::InputText(): BaseRule("input-text"), user(NULL), prompt(""), result(""), timeout(0){}

InputText::InputText(const std::string& user, const std::string& prompt, const std::string& result, const double timeout): 
    BaseRule("input-text"), user(user), prompt(prompt), result(result), timeout(timeout){}

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

    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}