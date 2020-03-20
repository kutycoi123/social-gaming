#ifndef WHEN_H
#define WHEN_H

#include "BaseRule.h"
#include "Case.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
    class When : public BaseRule{
        public:
            When(const std::vector<Case>& cases);

            void process(GameState&) override;
        private:
            std::vector<Case> cases;
    };
}
#endif
