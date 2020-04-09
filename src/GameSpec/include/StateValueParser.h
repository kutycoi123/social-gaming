#ifndef SOCIALGAMING_STATEVALUEPARSER_H
#define SOCIALGAMING_STATEVALUEPARSER_H

#include "StateValue.h"
#include "GameState.h"

static const std::string AUDIENCE = "audience";

static const std::string PLAYER = "player";

static const std::string SIZE = "size";

class StateValueParser {
public:
    StateValueParser(GameState&, const std::string&);
    std::optional<std::weak_ptr<StateValue>> getStateValue();
    std::optional<std::reference_wrapper<std::vector<GameState::StateValueUserPair>>> getPerUserValue();
    bool isPerUserValue();
private:
    GameState& gameState;
    std::string string;
    std::vector<std::string> splitString;
};

#endif //SOCIALGAMING_STATEVALUEPARSER_H
