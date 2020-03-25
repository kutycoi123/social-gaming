#ifndef ADD_H
#define ADD_H

#include "BaseRule.h"
#include "GameState.h"

namespace GameSpecification{
    class Add : public BaseRule{
        public:
            Add(std::string  to, const std::shared_ptr<StateValue>& value);

            void process(GameState&) override;

        private:
            std::string to;
            std::weak_ptr<StateValue> value;

//            int determineAmountToAdd(const StateValue &, GameState &);
    };
}

#endif
