#ifndef LOOP_H
#define LOOP_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
namespace GameSpecification{
class Loop : public ControlStructRule{
    public:
		Loop();
        Loop(const std::string& loopType, const std::string& failCondition);
        std::string getLoopType() const;
        std::string getFailCondition() const;
		    void process(GameState&) override;
        void parseRule(const nlohmann::json&) override; 
    private:
        std::string loopType;
        std::string failCondition;
};
}
#endif
