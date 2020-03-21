#ifndef MESSAGERULE_H
#define MESSAGERULE_H

#include "BaseRule.h"


namespace GameSpecification{
	class Message: public BaseRule{
		public:
			Message(const SpecValue&, const std::string&);

			void process(GameState&) override;
		private:
			SpecValue to;
			std::string	messValue;
	};
}


#endif
