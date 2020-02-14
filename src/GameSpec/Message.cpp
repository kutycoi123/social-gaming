#include "Message.h"


using GameSpecification::Message;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;

SpecValue Message::getTo() const{
	return _to;
}

std::string Message::getValue() const{
	return _messValue;
}

void Message::process(){
	//TODO: Add code to process message rule
}

