#include "InputChoice.h"


using GameSpecification::BaseRule;
using GameSpecification::SpecValue;
using GameSpecification::InputChoice;
using json = nlohmann::json;

InputChoice::InputChoice(const std::string& to, const std::string& prompt, const SpecValue& choices, const std::string& result, double timeout) : 
	BaseRule({}),
	to(to), 
	prompt(prompt), 
	choices(choices),
	result(result), 
	timeout(timeout) 
	{}


void InputChoice::process(GameState& gameState){
	//TODO: add logic for this rule
}
