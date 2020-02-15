#include "InputVote.h"


InputVote::InputVote(): BaseRule("input-vote"), _user(NULL), _prompt(""), _choices(""), _result(""), _timeout(0){}

InputVote::InputVote(const User& user,const std::string& prompt, const std::string& choices, const std::string& result, const double timeout), _user(user), 
    _prompt(prompt), _choices(choices), _result(result), _timeout(timeout){}

std::vector<User> InputVote::getUser() const{
    return _user;
}

std::string InputVote::getPrompt() const{
    return _prompt;
}

std::string InputVote::getChoice() const{
    return _choice
}

std::string InputVote::getResult() const{
    return _result
}

double InputVote::getTimeOut() const{
    return _timeout
}

void InputVote::process(){
    

}