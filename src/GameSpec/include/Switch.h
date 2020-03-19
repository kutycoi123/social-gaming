#ifndef SWITCH_H
#define SWITCH_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include "Case.h"
#include <string>
namespace GameSpecification{
class Switch : public BaseRule{
    public:
        Switch();
        Switch(const std::vector<Case>& cases);
        std::vector<Cases> getCases() const;
        void process(GameState&) override;
        void parseRule(const nlohmann::json&) override;
    private:
        std::vector<Case> cases;
};
}
#endif
