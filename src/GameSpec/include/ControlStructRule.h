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
			ControlStructRule(const ControlStructRule&);
			std::vector<std::shared_ptr<BaseRule>> getSubRules() const;
			void addSubRule(const BaseRule&);
			virtual void processRules();
		private:
			std::vector<std::shared_ptr<BaseRule>> _subRules;
	};
}
#endif
