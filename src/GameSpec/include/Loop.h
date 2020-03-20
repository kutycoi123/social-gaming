#ifndef LOOP_H
#define LOOP_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
namespace GameSpecification{
class Loop : public BaseRule{
    public:
		Loop();
        Loop(const nlohmann::json&);
        std::string getLoopType() const;
        std::string getFailCondition() const;
		void process(GameState&) override;
        void parseRule(const nlohmann::json&); 
    private:
        std::string loopType;
        std::string failCondition;
};
}
#endif
