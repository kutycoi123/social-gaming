#include "Scores.h"

#include <utility>

using GameSpecification::Scores;
using json = nlohmann::json;

Scores::Scores(std::string  scoreValue, bool ascending) :
        BaseRule({}),
        score(std::move(scoreValue)),
        ascending(ascending)
        {}

void Scores::process(GameState& gameState){
    auto optionalValue = gameState.getPerPlayerValue(score);
    if (optionalValue.has_value()) {
        auto listOfScores = optionalValue.value().get();
        for (auto pair : listOfScores) {
            // TODO: Add global message
        }
    }
}