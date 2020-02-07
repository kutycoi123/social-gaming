#ifndef PARALLELFOR_H
#define PARALLELFOR_H

#include "rule.h"
#include <string>
#include <vector>

class Parallelfor : public Rule{
    public:
        Parallelfor(std::vector<std::string> list, const std::string& element, std::vector<std::string> rules);
        std::vector<std::string> getList() const;
        std::string getElement() const;
        std::vector<std::string> getRules() const;
        void setList(const std::vector<std::string>& list);
        void setElement(const std::string& element);
        void setRules(const std::vector<std::string>& rules);
    private:
        std::vector<std::string> _list;
        std::string _element;
        std::vector<std::string> _rules;
};

#endif