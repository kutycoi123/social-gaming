#include "InputText.h"


InputText::InputText(): BaseRule("input-text"), _user(NULL), _prompt(""), _result(""), _timeout(0){}

InputText::InputText(const User& user, const std::string& prompt, const std::string& result, const double timeout): _user(user), 
    _prompt(prompt), _result(result), _timeout(timeout){}

User InputText::getUser() const{
    return _user
}

std::string InputText::getPrompt() const{
    return _prompt;
}

std::string InputText::getResult() const{
    return _result;
}

double InputText::getTimeOut() const{
    return _timeout
}

void process(){
       
}