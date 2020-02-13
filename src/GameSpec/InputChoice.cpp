#include "InputChoice.h"


using GameSpecification::BaseRule;
using GameSpecification::SpecValue;
using GameSpecification::InputChoiceRule;
using GameSpecification::MessageRule;

	std::string InputChoiceRule::getTo() const{
		return _to;
	}
	std::string InputChoiceRule::getResult() const{
		return _result;
	}
	std::string InputChoiceRule::getTimeout() const{
		return _timeout;
	}
	MessageRule InputChoiceRule::getPrompt() const{
		return _prompt;
	}
	
	SpecValue InputChoiceRule::getChoices() const{
		return _choices;
	}	

	void InputChoiceRule::process(){
		//TODO: add logic for this rule
	}


