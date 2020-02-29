#include "GlobalMessage.h"

using GameSpecification::GlobalMessage;

GlobalMessage::GlobalMessage(): BaseRule("global-message"), value(""){}

GlobalMessage::GlobalMessage(const std::string& value): value(value){}

std::string GlobalMessage::getValue() const{
    return value;
}

void GlobalMessage::process(GameState& gameState){
    
}