#ifndef ADD_H
#define ADD_H

#include "BaseRule.h"

namespace GameSpecification{
    class Add : public BaseRule{
        public:
            Add(const std::string& to, const SpecValue& value);

            void process(GameState&) override;

        private:
            std::string to;
            SpecValue value;
    };
}

#endif
