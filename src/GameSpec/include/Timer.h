#ifndef TIMER_H
#define TIMER_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Timer : public BaseRule{
    public:
        Timer();
        Timer(const double duration, const std::string& mode, const bool flag);
        double getDuration() const;
        std::string getMode() const;
        bool getFlag() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&) override;
    private:
        double duration;
        std::string mode;
        bool flag;
};
}
#endif
