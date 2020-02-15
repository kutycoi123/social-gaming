#include "Scores.h"

Scores::Scores(): BaseRule("scores"), _score(0), ascending(false){}

Scores::Scores(const double score, const bool ascending): BaseRule("scores"), _score(score), ascending(ascending){}

double Scores::getScore() const{
    return _score;
}

bool Scores::getAscending() const{
    return _ascending;
}

void Scores::process(){
    
}