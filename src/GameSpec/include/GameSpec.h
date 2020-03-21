//GameSpec.h
#ifndef GAMESPEC_H
#define GAMESPEC_H

#include <string>
#include <vector>
#include <unordered_map>
#include <boost/variant.hpp>
#include <nlohmann/json.hpp>
#include <memory>

#include "Add.h"
#include "Deal.h"
#include "Discard.h"
#include "Extend.h"
#include "ForEach.h"
#include "GlobalMessage.h"
#include "Inparallel.h"
#include "InputChoice.h"
#include "InputText.h"
#include "InputVote.h"
#include "Loop.h"
#include "Message.h"
#include "Parallelfor.h"
#include "Reverse.h"
#include "Scores.h"
#include "Shuffle.h"
#include "Sort.h"
#include "Switch.h"
#include "Timer.h"
#include "When.h"

using GameSpecification::BaseRule;

namespace GameSpecification{
	class GameSpec{
		public:
		    GameSpec(const nlohmann::json&);
		    std::list<std::shared_ptr<BaseRule>> getRules() const;

		private:
		    std::list<std::shared_ptr<BaseRule>> rules; 

		    nlohmann::json readSpec(const nlohmann::json&); 
		    void processSpec(const nlohmann::json&);
			std::shared_ptr<BaseRule> recursivelyParseSpec(const nlohmann::json&);
		    void addRule(std::shared_ptr<BaseRule>); 

	};	
}
#endif





