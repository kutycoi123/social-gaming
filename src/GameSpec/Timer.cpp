#include "Timer.h"

using GameSpecification::Timer;
using json = nlohmann::json;

Timer::Timer() : BaseRule(RuleType::TimerType), duration(0), mode(""), flag(false){}

Timer::Timer(double duration, const std::string& mode, bool flag)
    : BaseRule(RuleType::TimerType), duration(duration), mode(mode), flag(flag){}

double Timer::getDuration() const{
    return duration;
}
std::string  Timer::getMode() const{
    return mode;
}
std::optional<bool> Timer::getFlag() const{
    return flag;
}
void Timer::process(GameState& gameState){
    //TODO: Add logic to process timer rule
}

void Timer::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}