#include "Parallelfor.h"

using GameSpecification::Parallelfor;
using json = nlohmann::json;

Parallelfor::Parallelfor(const std::list<std::shared_ptr<BaseRule>>& childRules, std::vector<std::string> list, const std::string& element) : 
    BaseRule(childRules), 
    list(list), 
    element(element)
    {}

void Parallelfor::process(GameState& gameState){
	//TODO: Add code to process Parallelfor
}