#ifndef RULE_H
#define RULE_H

class Rule{
public:
	Rule();
	std::string GetRule() const;
	void SetRule(const std::string&); 	


private:
	std::string _ruleText;

};



#endif
