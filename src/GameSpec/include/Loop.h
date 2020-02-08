#ifndef LOOP_H
#define LOOP_H

#include "BaseRule.h"
#include <string>
#include <vector>
namespace GameSpecification{
class Loop : public BaseRule{
    public:
        Loop(const std::string& loopType, const std::string& failCondition, std::vector<std::string> rules);
        std::string getLoopType() const;
        std::string getFailCondition() const;
        std::vector<std::string> getRules() const;
        void setLoopType(const std::string& loopType);
        void setFailCondition(const std::string& failCondition);
        void setRules(const std::vector<std::string>& rules);
    private:
        std::string _loopType;
        std::string _failCondition;
        std::vector<std::string> _rules;
};
}
#endif
