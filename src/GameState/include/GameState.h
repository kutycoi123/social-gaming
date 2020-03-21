#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <utility>
#include <boost/variant.hpp>
#include "User.h"
#include "GameConfig.h"
#include "StateValue.h"

using ValueType = boost::make_recursive_variant<std::string, int,
        bool, double, std::vector<boost::recursive_variant_>,
        std::unordered_map<std::string, boost::recursive_variant_>>::type;

class GameState {
public:
    GameState();
    bool isGameStarted() const;
    void startGame();
    void endGame();

    std::optional<std::weak_ptr<StateValue>> getConstant(const std::string& key);
    std::optional<std::weak_ptr<StateValue>> getVariable(const std::string& key);
    std::optional<std::weak_ptr<StateValue>> getPerPlayerValue(const std::string& key);
    std::optional<std::weak_ptr<StateValue>> getPerAudienceValue(const std::string& key);

    void addConfig(const GameConfig& config);

    // These methods should only be called when GameState is begin constructed in the parser
    // TODO: Find out to how set up state value objects
    void addConstant(const std::string& key, const StateValue& value);
    void addVariable(const std::string& key, const StateValue& value);
    void addPerPlayer(const std::string& key, const StateValue& value);
    void addPerAudience(const std::string& key, const StateValue& value);
private:
    bool gameStarted;
    std::unordered_map<std::string, std::shared_ptr<StateValue>> constantsMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue>> variablesMap;
    // TODO: Change perPlayer/perAudience impl to be different from constantsMap/variablesMap
    std::unordered_map<std::string, std::shared_ptr<StateValue>> perPlayerMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue>> perAudienceMap;
    GameConfig gameConfig;
};

#endif
