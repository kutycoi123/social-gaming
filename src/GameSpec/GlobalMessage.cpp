#include "GlobalMessage.h"

using GameSpecification::GlobalMessage;
using json = nlohmann::json;

GlobalMessage::GlobalMessage(const std::string& value) : 
    BaseRule({}), 
    value(value){}

void GlobalMessage::process(GameState& gameState) {
    std::string parsedValue = parseValue(value);
    // TODO: This will have to become a for-loop once custom strings can be parsed
    gameState.addMessageToEntireSession(parsedValue);
}
