#ifndef WHEN_H
#define WHEN_H

#include "BaseRule.h"

namespace GameSpecification{
    class WhenCase{
        public:
            WhenCase(const std::string&, const std::list<std::shared_ptr<BaseRule>>&);
            
            //more functionality needed
        private:
            std::string condition;
            std::list<std::shared_ptr<BaseRule>> rules;
    };

    class When : public BaseRule{
        public:
            When(const std::vector<WhenCase>& cases);

            void process(GameState&) override;
        private:
            std::vector<WhenCase> cases;
    };
}

#endif
