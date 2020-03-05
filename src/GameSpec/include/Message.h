#ifndef MESSAGERULE_H
#define MESSAGERULE_H
#include <string>
#include "BaseRule.h"
#include "AbstractSpec.h"
#include <nlohmann/json.hpp>

namespace GameSpecification{
	class Message: public BaseRule{
		public:
			Message() : BaseRule("message"){}
			Message(const SpecValue& to, const std::string& val)
						: to(to), messValue(val){}
			SpecValue getTo() const;
			std::string getValue() const;	
			void process(GameState&) override;
			void parseRule(const nlohmann::json&) override;
		private:
			SpecValue to;
			std::string	messValue;

	};



}

#endif
