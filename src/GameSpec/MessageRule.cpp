#include "MessageRule.h"


using GameSpecification::MessageRule;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;

void MessageRule::setTo(const SpecValue& to){
	_to= to;
}

void MessageRule::setValue(const std::string& val){
	_messValue = val;
}

SpecValue MessageRule::getTo() const{
	return _to;
}

std::string MessageRule::getValue() const{
	return _messValue;
}
