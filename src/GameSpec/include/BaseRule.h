#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include <iostream>
#include "GameState.h"

// Forward dependancy declaration
// TODO: Remove when circular dependency between GameState and GameSpec is resolved
class GameState;

namespace GameSpecification{
enum RuleType{
	ForEachType,LoopType,InparallelType,ParallelforType,
	SwitchType,WhenType,ExtendType,ReverseType,ShuffleType,
	SortType,DealType,DiscardType,AddType,TimerType,InputChoiceType,
	InputTextType,InputVoteType,MessageType,GlobalMessageType,
	ScoresType,Unknown
};
	class BaseRule{
		public:
			static std::unordered_map<RuleType, std::string> rulemap;

			BaseRule();
			BaseRule(RuleType);
			std::string getRuleName() const;
			RuleType getRuleType() const;
            std::vector<std::shared_ptr<BaseRule>> getSubRules() const ;
            void addSubRule(std::shared_ptr<BaseRule> rule);
			virtual void process(GameState& gameState) = 0;
			virtual void parseRule(const nlohmann::json&) = 0;
		private:
            std::vector<std::shared_ptr<BaseRule>> subRules;
			RuleType ruleType;
	};
}
#endif
