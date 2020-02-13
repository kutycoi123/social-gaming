#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
namespace GameSpecification{
enum RuleType{
	ForEach,Loop,Inparallel,Parallelfor,
	Switch,When,Extend,Reverse,Shuffle,
	Sort,Deal,Discard,Add,Timer,InputChoice,
	InputText,InputVote,Message,GlobalMessage,
	Scores,Unknown
};
	class BaseRule{
		public:
			static std::unordered_map<std::string, RuleType> rulemap;

			BaseRule();
			BaseRule(const std::string&); 

			std::string getRuleName() const;
			RuleType getRuleType() const;
			void setRuleName(const std::string&);

		private:
			RuleType _ruleType;
			std::string _ruleName;
			
			RuleType getRuleTypeFromName(const std::string&);
	
	};
}
#endif
