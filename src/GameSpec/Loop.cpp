#include "Loop.h"

using GameSpecification::ControlStructRule;
using GameSpecification::Loop;

Loop::Loop() : ControlStructRule("loop"){}

Loop::Loop(const std::string& loopType, const std::string& failCondition) : ControlStructRule("loop"), 
    _loopType(loopType), _failCondition(failCondition){}

std::string Loop::getLoopType() const{
    return _loopType;
}

std::string Loop::getFailCondition() const{
    return _failCondition;
}

void Loop::process(){
	//TODO: add code to process loop rule
}
