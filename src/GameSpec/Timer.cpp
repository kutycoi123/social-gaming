#include "Timer.h"

using GameSpecification::Timer;
using json = nlohmann::json;

Timer::Timer(double duration, const std::string& mode, bool flag)
    : duration(duration), mode(mode), flag(flag){}

void Timer::process(GameState& gameState){
    //TODO: Add logic to process timer rule
}