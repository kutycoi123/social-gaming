#include "Rule.h"


Rule::Rule() : _rule(""){
}

inline std::string Rule::getRule() const{
	return _rule;
}


void Rule::setRule(const std::string& rule){
	_rule = rule;
}



