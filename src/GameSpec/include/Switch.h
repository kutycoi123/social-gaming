#ifndef SWITCH_H
#define SWITCH_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include "Case.h"
#include <string>
namespace GameSpecification{
class Switch : public BaseRule{
    public:
        Switch(const std::vector<Case>& cases);
        void process(GameState&) override;
    private:
        std::vector<Case> cases;
};
}
#endif
