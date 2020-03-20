#ifndef DEAL_H
#define DEAL_H

#include "BaseRule.h"

namespace GameSpecification{
    class Deal : public BaseRule{
        public:
            Deal(const std::string& from, const SpecValue& to, const int count);

            void process(GameState&) override;
            
        private:
            std::string from;
            SpecValue to;
            int count;
    };
}

#endif
