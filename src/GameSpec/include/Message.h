#ifndef MESSAGERULE_H
#define MESSAGERULE_H
#include <string>
#include "BaseRule.h"
#include "AbstractSpec.h"


/*

	{ "rule": "message",
	  "to": << list of recipients or a single player or audience member >>,
	  "value": << Message to send. Python style {} variable accesses are permitted.
	             E.g. "Great job, {player.name}!"  >>
	}

*/
namespace GameSpecification{
	class Message: public BaseRule{
		public:
			Message() : BaseRule("message"){}
			Message(const SpecValue& to, const std::string& val)
						: to(to), messValue(val){}
			SpecValue getTo() const;
			std::string getValue() const;	
			void process() override;
		private:
			SpecValue to;
			std::string	messValue;

	};



}

#endif
