#include "Rule.h"


Rule::Rule() : _rule(""){
}

inline std::string Rule::GetRule() const{
	return _rule;
}


void Rule::SetRule(const std::string& rule){
	_rule = rule;
}




