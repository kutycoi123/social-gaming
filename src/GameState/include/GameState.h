#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <boost/variant.hpp>
#include "User.h"

namespace StateValue {
    using valueType = boost::make_recursive_variant<std::string, int,
            bool, double, std::vector<boost::recursive_variant_>,
            std::unordered_map<std::string, boost::recursive_variant_>>::type;

    struct ConstantValue{
        const valueType value;
    };

    struct VariableValue{
        valueType value;
    };

    struct PerPlayerValue{
        valueType value;
    };

    struct PerAudienceValue{
        valueType value;
    };
}

class GameState {
public:
    GameState();
    bool isGameStarted() const;
    void startGame();
    void endGame();
    std::optional<std::weak_ptr<StateValue::ConstantValue>> getConstant(const std::string& key);
    std::optional<std::weak_ptr<StateValue::VariableValue>> getVariable(const std::string& key);
    std::optional<std::weak_ptr<StateValue::PerPlayerValue>> getPerPlayerValue(const std::string& key);
    std::optional<std::weak_ptr<StateValue::PerAudienceValue>> getPerAudienceValue(const std::string& key);
private:
    bool gameStarted;
    std::unordered_map<std::string, std::shared_ptr<StateValue::ConstantValue>> constantsMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue::VariableValue>> variablesMap;
    // TODO: Will change perPlayer/perAudience impl to be different from constantsMap/variablesMap
    std::unordered_map<std::string, std::shared_ptr<StateValue::PerPlayerValue>> perPlayerMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue::PerAudienceValue>> perAudienceMap;
};

#endif
