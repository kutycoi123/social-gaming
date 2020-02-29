#ifndef INPARALLEL_H
#define INPARALLEL_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <string>
#include <vector>
namespace GameSpecification{
class Inparallel : public ControlStructRule{
    public:
        Inparallel();
		void process(GameState&) override;
    private:
};
}
#endif
