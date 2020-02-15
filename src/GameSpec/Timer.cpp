#include "Timer.h"

using GameSpecification::Timer;

Timer::Timer() : BaseRule("timer"), _duration(0), _mode(""), _flag(false){}

Timer::Timer(const double duration, const std::string& mode, const bool flag): BaseRule("timer"), _duration(duration), 
    _mode(mode), _flag(flag){}

double Timer::getDuration() const{
    return _duration;
}
std::string  Timer::getMode() const{
    return _mode;
}
bool Timer::getFlag() const{
    return _flag;
}
void Timer::process(){


}