#include "Time.h"

Timer::Timer(): BaseRule("timer"), _duration(0), _mode(""), bool(false){}

Timmer::Timer(const double duration, const std::string& mode, const bool flag): BaseRule("timer"), _duration(duration), _mode(mode), _flag(flag)

double Timer::getDuration() const{
    return duration;
}

std::string Timer::getMode() const{
    return mode;
}
double Timer::getFlag() const{
    return flag;
}

void Timer::process(){

} 