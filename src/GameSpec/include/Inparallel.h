#ifndef INPARALLEL_H
#define INPARALLEL_H

#include "rule.h"
#include <string>
#include <vector>

class Inparallel : public Rule{
    public:
        Inparallel(std::vector<std::string> rules);
        std::vector<std::string> getRules() const;
        void setRules(const std::vector<std::string>& rules);
    private:
        std::vector<std::string> _rules;
};

#endif