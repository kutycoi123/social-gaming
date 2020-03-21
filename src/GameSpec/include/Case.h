#ifndef CASE_H
#define CASE_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Case : BaseRule{
    public:
        Case();
        Case(const nlohmann::json&);
        std::string getValue();
        void process(GameState&) override;
        void parseRule(const nlohmann::json&);
    private:
        std::string value;
};
}
#endif
