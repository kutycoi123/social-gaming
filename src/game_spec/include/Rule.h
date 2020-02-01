#ifndef RULE_H
#define RULE_H

class Rule{
public:
	Rule();
	std::string getRule() const;
	void setRule(const std::string&); 	


private:
	std::string _rule;

};




#endif
