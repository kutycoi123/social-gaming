#ifndef TIMER_H
#define TIMER_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include <optional>
namespace GameSpecification{
class Timer : public BaseRule{
    public:
        Timer();
        Timer(const nlohmann::json&);
        double getDuration() const;
        std::string getMode() const;
        std::optional<bool> getFlag() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&);
    private:
        double duration;
        std::string mode;
        std::optional<bool> flag;
        //TODO: Add "rules" field when more details are provided
};
}
#endif
