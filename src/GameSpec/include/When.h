#ifndef WHEN_H
#define WHEN_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include "Case.h"
#include <string>
namespace GameSpecification{
class When : public BaseRule{
    public:
        When();
        When(const std::vector<Case>& cases);
        std::vector<Cases> getCases() const;
        void process(GameState&) override;
        void parseRule(const nlohmann::json&) override;
    private:
        std::vector<Case> cases;
};
}
#endif
