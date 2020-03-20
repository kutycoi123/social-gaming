#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <list>
#include <memory>
#include <unordered_map>
#include <iostream>

class GameState;

namespace GameSpecification{
	class BaseRule : public std::enable_shared_from_this<BaseRule>{
		public:
            BaseRule(); //to be removed later
			BaseRule(const std::list<std::shared_ptr<BaseRule>>&);

            std::shared_ptr<BaseRule> getCurrentPtr() const noexcept;
			std::shared_ptr<BaseRule> getNextPtr() const noexcept;

			virtual void process(GameState& gameState) = 0;

		protected:
			std::list<std::shared_ptr<BaseRule>> childRules;
	};
}
#endif
