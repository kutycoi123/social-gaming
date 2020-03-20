#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <iostream>

class GameState;

namespace GameSpecification{
	class BaseRule : public std::enable_shared_from_this<BaseRule>{
		public:
            BaseRule(); //to be removed later
			BaseRule(std::shared_ptr<BaseRule>& parentRule, std::shared_ptr<BaseRule>& nextRule, const std::vector<std::shared_ptr<BaseRule>>& subRules);

            std::shared_ptr<BaseRule> getCurrentPtr() const noexcept;
			std::shared_ptr<BaseRule> getNextPtr() const noexcept;

			virtual void process(GameState& gameState) = 0;

		protected:
			std::shared_ptr<BaseRule> next;
			std::shared_ptr<BaseRule> parent;
            std::vector<std::shared_ptr<BaseRule>> subRules;

	};
}
#endif
