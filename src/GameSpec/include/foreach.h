#ifndef FOREACH.H
#define FOREACH.H

#include "rule.h"
#include "GameSpec.h"
#include <string>
#include <vector>

class ForEach : public Rule{
    public:
        ForEach();
        ForEach(const SpecValue& list, const std::string& element, std::vector<std::string>& rules);
        SpecValue getList() const;
        std::string getElement() const;
        std::vector<std::string> getRules() const;
        void setList(const SpecValue>& list);
        void setElement(const std::string& element);
        void setRules(const std::vector<std::string>& rules);
    private:
        //spec value take all value
        SpecValue _list;
        std::string _element;
        std::vector<Rule> _rules;
};

#endif