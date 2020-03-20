#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include <iostream>
#include "GameState.h"
#include "AbstractSpec.h"

class GameState;

namespace GameSpecification{
	class BaseRule : public std::enable_shared_from_this<BaseRule>{
		public:
			BaseRule();
			BaseRule(RuleType);
			std::string getRuleName() const;
			RuleType getRuleType() const;
            std::vector<std::shared_ptr<BaseRule>> getSubRules() const ;
			std::shared_ptr<BaseRule> getPtr() ;
			void setNextPtr(const std::shared_ptr<BaseRule>&);
			std::shared_ptr<BaseRule> getNextPtr() const;
            void addSubRule(std::shared_ptr<BaseRule> rule);
			void setParentPtr(const std::shared_ptr<BaseRule>&);
			std::shared_ptr<BaseRule> getParentPtr() const;
			virtual void process(GameState& gameState) = 0;

		protected:

			RuleType ruleType;
			std::shared_ptr<BaseRule> next;
			std::shared_ptr<BaseRule> parent;
            std::vector<std::shared_ptr<BaseRule>> subRules;
	};
}
#endif
