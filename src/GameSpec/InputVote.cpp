#include "InputVote.h"

using GameSpecification::InputVote;
using json = nlohmann::json;
InputVote::InputVote(): 
    BaseRule(RuleType::InputVoteType), user(NULL), prompt(""), choices(""), result(""), timeout(0){}

InputVote::InputVote(const std::string& user,const std::string& prompt, const std::string& choices, const std::string& result, const double timeout): 
    BaseRule(RuleType::InputVoteType), user(user), prompt(prompt), choices(choices), result(result), timeout(timeout){}

std::string InputVote::getUser() const{
    return user;
}

std::string InputVote::getPrompt() const{
    return prompt;
}

std::string InputVote::getChoice() const{
    return choices;
}

std::string InputVote::getResult() const{
    return result;
}

double InputVote::getTimeOut() const{
    return timeout;
}

void InputVote::process(GameState& gameState){

}

void InputVote::parseRule(const json &ruleJson){
    try{
        user = ruleJson.at("user").get<std::string>();
        prompt = ruleJson.at("prompt").get<std::string>();
        choices = ruleJson.at("choices").get<std::string>();
        result = ruleJson.at("result").get<std::string>();
        if(ruleJson.find("timeout") != ruleJson.end())
            timeout = ruleJson.at("timeout").get<double>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}