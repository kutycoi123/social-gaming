#include "GlobalMessage.h"

using GameSpecification::GlobalMessage;

GlobalMessage::GlobalMessage(): BaseRule("global-message"), _value(""){}

GlobalMessage::GlobalMessage(const std::string& value): _value(value){}

std::string GlobalMessage::getValue() const{
    return _value;
}

void GlobalMessage::process(){
    
}