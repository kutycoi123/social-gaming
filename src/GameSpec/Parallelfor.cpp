#include "Parallelfor.h"

using GameSpecification::Parallelfor;
using json = nlohmann::json;

Parallelfor::Parallelfor(std::vector<std::string> list, const std::string& element) 
    : list(list), element(element){}

void Parallelfor::process(GameState& gameState){
	//TODO: Add code to process Parallelfor
}