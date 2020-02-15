#include "Scores.h"

using GameSpecification::Scores;

Scores::Scores(): BaseRule("scores"), _score(0), _ascending(false){}

Scores::Scores(const double score, const bool ascending): BaseRule("scores"), _score(score), _ascending(ascending){}

double Scores::getScore() const{
    return _score;
}

bool Scores::getAscending() const{
    return _ascending;
}

void Scores::process(){
    
}