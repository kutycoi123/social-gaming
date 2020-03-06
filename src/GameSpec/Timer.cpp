#include "Timer.h"

using GameSpecification::Timer;
using json = nlohmann::json;
Timer::Timer() : BaseRule("timer"), duration(0), mode(""), flag(false){}

Timer::Timer(double duration, const std::string& mode, bool flag): BaseRule("timer"), duration(duration), 
    mode(mode), flag(flag){}

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

}

void Timer::parseRule(const json &ruleJson){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}