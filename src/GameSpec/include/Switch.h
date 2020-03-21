#ifndef SWITCH_H
#define SWITCH_H

#include "BaseRule.h"
#include "Case.h"
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
