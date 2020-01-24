#include "Rule.h"


Rule::Rule() : _ruleText(""){
}

inline std::string Rule::getRule() const{
	return _ruleText;
}


void Rule::SetRule(const std::string& rule){
	_ruleText = rule;
}




