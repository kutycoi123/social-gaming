#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <utility>
#include <boost/variant.hpp>
#include "User.h"
#include "GameConfig.h"
#include "StateValue.h"
#include "StateValueBoolean.h"
#include "StateValueNumber.h"
#include "StateValueString.h"
#include "StateValueList.h"
#include "StateValueMap.h"
#include <optional>

class GameState {
public:
    GameState();
    bool isGameStarted() const;
    void startGame();
    void endGame();
    enum ValueType {
        CONSTANT,
        VARIABLE,
        PER_PLAYER,
        PER_AUDIENCE
    };

    std::optional<std::weak_ptr<const StateValue>> getConstant(const std::string& key);
    std::optional<std::weak_ptr<const StateValue>> getConstantOrVariable(const std::string& key);
    std::optional<std::weak_ptr<StateValue>> getVariable(const std::string& key);
    std::optional<std::weak_ptr<StateValue>> getPerPlayerValue(const std::string& key);
    std::optional<std::weak_ptr<StateValue>> getPerAudienceValue(const std::string& key);

    void addConfig(const GameConfig& config);

    // These methods should only be called when GameState is begin constructed in the parser
    void addValue(const std::string& key, StateValueBoolean value, const ValueType& valueType);
    void addValue(const std::string &key, StateValueNumber value, const ValueType& valueType);
    void addValue(const std::string &key, StateValueString value, const ValueType& valueType);
    void addValue(const std::string &key, StateValueList value, const ValueType& valueType);
    void addValue(const std::string &key, StateValueMap value, const ValueType& valueType);
private:
    bool gameStarted;
    std::unordered_map<std::string, std::shared_ptr<const StateValue>> constantsMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue>> variablesMap;
    // TODO: Change perPlayer/perAudience impl to be different from constantsMap/variablesMap
    std::unordered_map<std::string, std::shared_ptr<StateValue>> perPlayerMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue>> perAudienceMap;
    GameConfig gameConfig;

    void insertIntoCorrectMap(const GameState::ValueType &valueType,
                              std::pair<std::string, std::shared_ptr<StateValue>>& pair);
};

#endif
