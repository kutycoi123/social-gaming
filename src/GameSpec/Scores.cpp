#include "Scores.h"

using GameSpecification::Scores;
using json = nlohmann::json;

Scores::Scores(): BaseRule(RuleType::ScoresType), score(0), ascending(false){}

Scores::Scores(const json &ruleJson) : BaseRule(RuleType::ScoresType){
    parseRule(ruleJson);
}

double Scores::getScore() const{
    return score;
}

bool Scores::getAscending() const{
    return ascending;
}

void Scores::process(GameState& gameState){
    
}

void Scores::parseRule(const json &ruleJson){
    try{
        score = ruleJson.at("score").get<int>();
        ascending = ruleJson.at("ascending").get<bool>();
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}