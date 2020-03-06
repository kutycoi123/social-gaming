#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <utility>
#include <boost/variant.hpp>
#include "User.h"

using ValueType = boost::make_recursive_variant<std::string, int,
        bool, double, std::vector<boost::recursive_variant_>,
        std::unordered_map<std::string, boost::recursive_variant_>>::type;

namespace StateValue {
    struct ConstantValue{
        explicit ConstantValue(ValueType value) : value(std::move(value))
        {}
        const ValueType value;
    };

    struct VariableValue{
        explicit VariableValue(ValueType value) : value(std::move(value))
        {}
        ValueType value;
    };

    struct PerPlayerValue{
        explicit PerPlayerValue(ValueType value) : value(std::move(value))
        {}
        ValueType value;
    };

    struct PerAudienceValue{
        explicit PerAudienceValue(ValueType value) : value(std::move(value))
        {}
        ValueType value;
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

    // These methods should only be called when GameState is begin constructed in the parser
    // TODO: Find a way to enforce this (maybe with a design pattern)
    void addConstant(const std::string& key, const ValueType& value);
    void addVariable(const std::string& key, const ValueType& value);
    void addPerPlayer(const std::string& key, const ValueType& value);
    void addPerAudience(const std::string& key, const ValueType& value);
private:
    bool gameStarted;
    std::unordered_map<std::string, std::shared_ptr<StateValue::ConstantValue>> constantsMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue::VariableValue>> variablesMap;
    // TODO: Will change perPlayer/perAudience impl to be different from constantsMap/variablesMap
    std::unordered_map<std::string, std::shared_ptr<StateValue::PerPlayerValue>> perPlayerMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue::PerAudienceValue>> perAudienceMap;
};

#endif
