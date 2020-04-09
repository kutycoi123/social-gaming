#include "StateValueParser.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

StateValueParser::StateValueParser(GameState& gameState, const std::string& string) :
    gameState(gameState),
    string(string)
{
     boost::algorithm::split(splitString, string, boost::is_any_of("."));
}

std::optional<std::weak_ptr<StateValue>> StateValueParser::getStateValue(const std::string& value) {
    if (isPerUserValue()){
        return std::nullopt;
    }
    auto currVariable = gameState.getVariable(value);
    for (auto i = splitString.begin()+1; i < splitString.end(); ++i){
        if (!currVariable.has_value()){
            return std::nullopt;
        }
        if (auto v = currVariable.value().lock()){
            auto variable = static_cast<const StateValueMap*>(v.get());
            currVariable = variable->getValue(*i);
        }
    }
    return currVariable;
}

bool StateValueParser::isPerUserValue(){
    if (!splitString.empty()){
        return splitString[0] == PLAYER || splitString[0] == AUDIENCE;
    }
    return false;
}


std::optional<std::reference_wrapper<std::vector<GameState::StateValueUserPair>>> StateValueParser::getPerPlayerAudienceValue(const std::string& value) {
    if (!isPerUserValue()){
        return std::nullopt;
    }
    return gameState.getPerPlayerOrPerAudienceValue(value);
}
