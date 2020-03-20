#include "Loop.h"

using GameSpecification::Loop;
using json = nlohmann::json;

Loop::Loop(const std::string& loopType, const std::string& failCondition) 
    : loopType(loopType), failCondition(failCondition){}

void Loop::process(GameState& gameState){
	//TODO: add code to process loop rule
}