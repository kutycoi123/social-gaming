#include "Scores.h"

using GameSpecification::Scores;

Scores::Scores(): BaseRule("scores"), score(0), ascending(false){}

Scores::Scores(const double score, const bool ascending): BaseRule("scores"), score(score), ascending(ascending){}

double Scores::getScore() const{
    return score;
}

bool Scores::getAscending() const{
    return ascending;
}

void Scores::process(GameState& gameState){
    
}

void Scores::parseRule(const nlohmann::json &json){
    //TODO: Add parsing logic
}