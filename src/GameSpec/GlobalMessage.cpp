#include "GlobalMessage.h"

using GameSpecification::GlobalMessage;
using json = nlohmann::json;

GlobalMessage::GlobalMessage(const std::string& value) : 
    BaseRule({}), 
    value(value){}

void GlobalMessage::process(GameState& gameState) {
    std::string parsedValue = parseValue(value);
    gameState.addMessages(parsedValue);
}

std::string GameSpecification::GlobalMessage::parseValue(const std::string& basicString) {
    // TODO: Parse value so that every item in {} refers to it's associated variable/constant
    std::string parsedValue;
    parsedValue.append(basicString);
    return parsedValue;
}
