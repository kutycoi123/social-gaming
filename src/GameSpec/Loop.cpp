#include "Loop.h"

using GameSpecification::ControlStructRule;
using GameSpecification::Loop;

Loop::Loop() : ControlStructRule("loop"){}

Loop::Loop(const std::string& loopType, const std::string& failCondition) : ControlStructRule("loop"), 
    loopType(loopType), failCondition(failCondition){}

std::string Loop::getLoopType() const{
    return loopType;
}

std::string Loop::getFailCondition() const{
    return failCondition;
}

void Loop::process(){
	//TODO: add code to process loop rule
}
