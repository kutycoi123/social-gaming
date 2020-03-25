#ifndef MESSAGERULE_H
#define MESSAGERULE_H

#include "BaseRule.h"


namespace GameSpecification{
	class Message: public BaseRule{
		public:
			Message(const std::shared_ptr<StateValue>&, std::string );

			void process(GameState&) override;
		private:
			std::weak_ptr<StateValue> to;
			std::string	messValue;
	};
}


#endif
