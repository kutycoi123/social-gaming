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
        Sort(const std::string& list, const std::string& _key);
        std::string getList() const;
        std::string getKey() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&) override;
    private:
        std::string list;
        std::optional<std::string> key;
};
}
#endif

// sort, time, input text, input vote, globalmessage, score