#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <boost/variant.hpp>

namespace StateValue {
    struct ConstantValue{
        const boost::variant<std::string, int,
                bool, double, std::vector<std::string>,
                std::unordered_map<std::string, std::string>> value;
    };

    struct VariableValue{
        boost::variant<std::string, int,
                bool, double, std::vector<std::string>,
                std::unordered_map<std::string, std::string>> value;
    };

    struct PerPlayerValue{
        boost::variant<std::string, int,
                bool, double, std::vector<std::string>,
                std::unordered_map<std::string, std::string>> value;
    };

    struct PerAudienceValue{
        boost::variant<std::string, int,
                bool, double, std::vector<std::string>,
                std::unordered_map<std::string, std::string>> value;
    };
}

class GameState {
public:
    GameState();
    bool isGameStarted() const;
    void startGame();
    void endGame();
    std::optional<std::weak_ptr<StateValue::ConstantValue>> getConstant(const std::string &key);
    std::optional<std::weak_ptr<StateValue::VariableValue>> getVariable(const std::string &key);
    std::optional<std::weak_ptr<StateValue::PerPlayerValue>> getPerPlayerValue(const std::string&);
    std::optional<std::weak_ptr<StateValue::PerAudienceValue>> getPerAudienceValue(const std::string&);
private:
    bool gameStarted;
    std::unordered_map<std::string, std::shared_ptr<StateValue::ConstantValue>> constantsMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue::VariableValue>> variablesMap;
    // TODO: Will change perPlayer/perAudience impl to be different from constantsMap/variablesMap
    std::unordered_map<std::string, std::shared_ptr<StateValue::PerPlayerValue>> perPlayerMap;
    std::unordered_map<std::string, std::shared_ptr<StateValue::PerAudienceValue>> perAudienceMap;
};

#endif
