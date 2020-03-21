#ifndef WHEN_H
#define WHEN_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include "Case.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class When : public BaseRule{
    public:
        When();
        When(const nlohmann::json&);
        const std::vector<Case>& getCases() const;
        void process(GameState&) override;
        void parseRule(const nlohmann::json&);
    private:
        std::vector<Case> cases;
};
}
#endif
