#include "Message.h"


using GameSpecification::MessageRule;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;

SpecValue MessageRule::getTo() const{
	return _to;
}

std::string MessageRule::getValue() const{
	return _messValue;
}

void MessageRule::process(){
	//TODO: Add code to process message rule
}

