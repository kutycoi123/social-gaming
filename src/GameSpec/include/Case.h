#ifndef CASE_H
#define CASE_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <string>
namespace GameSpecification{
class Case{
    public:
        Case();
        Case(const std::string& value, const std::vector<BaseRule>&);
        std::string getValue();
        std::vector<BaseRule> getRules() const;
        std::string getValue();
    private:
        std::string value;
        std::vector<BaseRule> rules;
};
}
#endif
