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
        Timer(double duration, const std::string& mode, bool flag);
        double getDuration() const;
        std::string getMode() const;
        std::optional<bool> getFlag() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&) override;
    private:
        double duration;
        std::string mode;
        std::optional<bool> flag;
        //TODO: Add "rules" field when more details are provided
};
}
#endif
