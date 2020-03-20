#include "Scores.h"

using GameSpecification::Scores;
using json = nlohmann::json;

Scores::Scores(double score, bool ascending)
        : score(score), ascending(ascending){}

void Scores::process(GameState& gameState){
    
}