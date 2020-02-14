#include "InputChoice.h"


using GameSpecification::BaseRule;
using GameSpecification::SpecValue;
using GameSpecification::InputChoice;
using GameSpecification::Message;

	std::string InputChoice::getTo() const{
		return _to;
	}
	std::string InputChoice::getResult() const{
		return _result;
	}
	std::string InputChoice::getTimeout() const{
		return _timeout;
	}
	Message InputChoice::getPrompt() const{
		return _prompt;
	}
	
	SpecValue InputChoice::getChoices() const{
		return _choices;
	}	

	void InputChoice::process(){
		//TODO: add logic for this rule
	}


