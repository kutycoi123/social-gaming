#ifndef LOOP_H
#define LOOP_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <string>
#include <vector>
namespace GameSpecification{
class Loop : public ControlStructRule{
    public:
		Loop();
        Loop(const std::string& loopType, const std::string& failCondition);
        std::string getLoopType() const;
        std::string getFailCondition() const;
		void process() override;
    private:
        std::string _loopType;
        std::string _failCondition;
};
}
#endif
