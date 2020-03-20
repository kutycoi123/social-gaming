#ifndef SORT_H
#define SORT_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
namespace GameSpecification{
class Sort : public BaseRule{
    public:
        Sort();
        Sort(const nlohmann::json&);
        std::string getList() const;
        std::optional<std::string> getKey() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&);
    private:
        std::string list;
        std::optional<std::string> key;
};
}
#endif
