#ifndef FOREACH_H
#define FOREACH_H

#include "GameSpec.h"

namespace GameSpecification{
    class ForEach : public BaseRule{
        public:
            ForEach(const std::list<std::shared_ptr<BaseRule>>& childRules, const std::shared_ptr<StateValue>& list, std::string element);

            void process(GameState&) override; 
        
        private:
            //spec value take all value
            std::weak_ptr<StateValue> list;
            std::string element;
    };
}

#endif
