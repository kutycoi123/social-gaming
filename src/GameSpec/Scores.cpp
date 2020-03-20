#include "Scores.h"

using GameSpecification::Scores;
using json = nlohmann::json;

Scores::Scores(double score, bool ascending)
        : score(score), ascending(ascending){}

void Scores::process(GameState& gameState){
    
}

/*
void Scores::parseRule(const json &ruleJson){
    try{
        score = ruleJson.at("score").get<int>();
        ascending = ruleJson.at("ascending").get<bool>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}
*/