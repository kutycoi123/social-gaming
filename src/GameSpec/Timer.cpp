#include "Timer.h"

using GameSpecification::Timer;

Timer::Timer() : BaseRule("timer"), duration(0), mode(""), flag(false){}

Timer::Timer(const double duration, const std::string& mode, const bool flag): BaseRule("timer"), duration(duration), 
    mode(mode), flag(flag){}

double Timer::getDuration() const{
    return duration;
}
std::string  Timer::getMode() const{
    return mode;
}
bool Timer::getFlag() const{
    return flag;
}
void Timer::process(GameState& gameState){

}

void Timer::parseRule(const nlohmann::json &json){
    //TODO: Add parsing logic
}