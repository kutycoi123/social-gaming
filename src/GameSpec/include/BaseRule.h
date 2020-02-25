#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
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
			static std::unordered_map<std::string, RuleType> rulemap;

			BaseRule();
			BaseRule(const std::string&); 

			std::string getRuleName() const;
			RuleType getRuleType() const;
			void setRuleName(const std::string&);
			virtual void process() = 0;

		private:
			RuleType ruleType;
			std::string ruleName;
			
			RuleType getRuleTypeFromName(const std::string&);
	
	};
}
#endif
