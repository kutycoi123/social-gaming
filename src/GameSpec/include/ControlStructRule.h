#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include <memory>
#include "BaseRule.h"

namespace GameSpecification{
	class ControlStructRule : public BaseRule{
		public:
			ControlStructRule();
			ControlStructRule(RuleType);
			std::vector<std::shared_ptr<BaseRule>> getSubRules() const;
			void addSubRule(std::shared_ptr<BaseRule>);
			virtual void process(GameState&) = 0;
			virtual void parseRule(const nlohmann::json&) = 0;
		private:
			std::vector<std::shared_ptr<BaseRule>> subRules;
	};
}
#endif
