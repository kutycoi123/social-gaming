#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <list>
#include <memory>
#include <unordered_map>
#include <iostream>
#include "GameState.h"

namespace GameSpecification{
	class BaseRule : public std::enable_shared_from_this<BaseRule>{
		public:
			explicit BaseRule(const std::list<std::shared_ptr<BaseRule>>&);
            
            void setNextPtr(const std::list<std::shared_ptr<BaseRule>>& ptrList);
			void addNextPtr(const std::shared_ptr<BaseRule>& ptr);
			std::list<std::shared_ptr<BaseRule>> getNextPtr() const noexcept;


			virtual void process(GameState& gameState) = 0;           

		protected:
			std::list<std::shared_ptr<BaseRule>> childRules;
            std::list<std::shared_ptr<BaseRule>> next;	
        };
}
#endif
