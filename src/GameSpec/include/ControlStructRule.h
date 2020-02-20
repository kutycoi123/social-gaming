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
			ControlStructRule(const std::string&);
			std::vector<std::shared_ptr<BaseRule>> getSubRules() const;
			void addSubRule(std::shared_ptr<BaseRule>);
			virtual void process() = 0;
		private:
			std::vector<std::shared_ptr<BaseRule>> subRules;
	};
}
#endif
