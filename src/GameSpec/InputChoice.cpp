#include "InputChoice.h"


using GameSpecification::BaseRule;
using GameSpecification::SpecValue;
using GameSpecification::InputChoice;
using GameSpecification::Message;

	std::string InputChoice::getTo() const{
		return to;
	}
	std::string InputChoice::getResult() const{
		return result;
	}
	std::string InputChoice::getTimeout() const{
		return timeout;
	}
	Message InputChoice::getPrompt() const{
		return prompt;
	}
	
	SpecValue InputChoice::getChoices() const{
		return choices;
	}	

	void InputChoice::process(){
		//TODO: add logic for this rule
	}


