#ifndef EXTEND_H
#define EXTEND_H

#include "BaseRule.h"
#include "ExtendVisitor.h"
#include "GameState.h"

namespace GameSpecification{
    class Extend : public BaseRule{
        public:
            Extend(std::string  target, const std::shared_ptr<StateValue>& list);

            void process(GameState&) override; 

        private:
            std::string target;
            std::weak_ptr<StateValue> list;
    };
}
#endif
