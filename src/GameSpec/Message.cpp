#include "Message.h"


using GameSpecification::Message;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;

SpecValue Message::getTo() const{
	return to;
}

std::string Message::getValue() const{
	return messValue;
}

void Message::process(GameState& gameState){
	//TODO: Add code to process message rule
}

