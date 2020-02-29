#include "Shuffle.h"

using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
Shuffle::Shuffle() : BaseRule("shuffle"), list(""){}

Shuffle::Shuffle(const std::string& list): BaseRule("shuffle"), list(list){}

std::string Shuffle::getList() const{
    return list;
}

void Shuffle::process(GameState& gameState){
	//TODO: Add code to process shuffle rule
}


