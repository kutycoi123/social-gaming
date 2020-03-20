#ifndef FOREACH_H
#define FOREACH_H

#include "GameSpec.h"

namespace GameSpecification{
    class ForEach : public BaseRule{
        public:
            ForEach(const std::list<std::shared_ptr<BaseRule>>&,const SpecValue& list, const std::string& element);

            void process(GameState&) override; 
        
        private:
            //spec value take all value
            SpecValue list;
            std::string element;
    };
}

#endif
