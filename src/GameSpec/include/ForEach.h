#ifndef FOREACH_H
#define FOREACH_H

#include "AbstractSpec.h"
#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <cassert>
#include "Add.h"
#include "Deal.h"
#include "Discard.h"
#include "Extend.h"
#include "GlobalMessage.h"
#include "Inparallel.h"

#include "InputChoice.h"
#include "InputText.h"
#include "InputVote.h"
#include "Loop.h"
#include "Message.h"
#include "Parallelfor.h"
#include "Reverse.h"

#include "Shuffle.h"
#include "Sort.h"
#include "Timer.h"
#include "Scores.h"
#include "GameSpecHelper.h"

namespace GameSpecification{
class ForEach : public BaseRule{
    public:
        ForEach();
        ForEach(const SpecValue& list, const std::string& element);
        SpecValue getList() const;
        std::string getElement() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&) override;
    private:
        //spec value take all value
        SpecValue list;
        std::string element;
};
}
#endif
