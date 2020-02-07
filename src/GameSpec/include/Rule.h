#ifndef RULE_H
#define RULE_H

#include <string>

class Rule{
    public:
        Rule(const std::string& rule);
        std::string getRule() const;
        void setRule(const std::string& rule);
    private:
        std::string _rule;
};

#endif