#ifndef CASE_H
#define CASE_H

#include "BaseRule.h"
#include <string>
namespace GameSpecification{
class Case : BaseRule{
    public:
        Case(const nlohmann::json&);
        void process(GameState&) override;
    private:
        std::string value;
};
}
#endif
