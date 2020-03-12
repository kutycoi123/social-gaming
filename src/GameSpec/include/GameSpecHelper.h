#ifndef GAMESPECHELPER_H
#define GAMESPECHELPER_H
#include <nlohmann/json.hpp>
#include <vector>
#include <algorithm>
#include "AbstractSpec.h"
#include "BaseRule.h"
/*
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

#include "Shuffle.h"
#include "Sort.h"
#include "Timer.h"
#include "Scores.h"
*/
using nlohmann::json;
class Add;
class Deal;
class Discard;
class Extend;
class GlobalMessage;
class InputChoice;
class InputText;
class InputVote;
class Message;
class Reverse;
class Shuffle;
class Sort;
class Timer;
class Scores;
namespace GameSpecification{
//Note: This function are not dealing with ForEach, ParallelFor, Loop, Inparallelfor
//		because when calling this function inside those classes, it would cause "invalid use of incomplete type"
static std::shared_ptr<BaseRule> getRulePtrFromJson(RuleType ruleType){
	switch(ruleType){
		case RuleType::AddType: 
			return std::shared_ptr<BaseRule>(new Add());
		case RuleType::ExtendType:
			return std::shared_ptr<BaseRule>(new Extend());
		case RuleType::ReverseType:
			return std::shared_ptr<BaseRule>(new Reverse());
		case RuleType::ShuffleType:
			return std::shared_ptr<BaseRule>(new Shuffle());
		case RuleType::SortType:
			return std::shared_ptr<BaseRule>(new Sort());
		case RuleType::DealType:
			return std::shared_ptr<BaseRule>(new Deal());
		case RuleType::DiscardType:
			return std::shared_ptr<BaseRule>(new Discard());
		case RuleType::InputChoiceType:
			return std::shared_ptr<BaseRule>(new InputChoice());
		case RuleType::InputTextType:
			return std::shared_ptr<BaseRule>(new InputText());
		case RuleType::InputVoteType:
			return std::shared_ptr<BaseRule>(new InputVote());
		case RuleType::MessageType:
			return std::shared_ptr<BaseRule>(new Message());
		case RuleType::ScoresType:
			return std::shared_ptr<BaseRule>(new Scores());
		case RuleType::TimerType:
			return std::shared_ptr<BaseRule>(new Timer());
		case RuleType::GlobalMessageType:
			return std::shared_ptr<BaseRule>(new GlobalMessage());
		default:
			return nullptr;
	}
}
}
#endif
