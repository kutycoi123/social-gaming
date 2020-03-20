#ifndef INPUTCHOICERULE_H
#define INPUTCHOICERULE_H

#include "GameSpec.h"
#include "Message.h"
#include <nlohmann/json.hpp>

namespace GameSpecification{
	class InputChoice: public BaseRule{
		
		public:
			InputChoice();
			InputChoice(const nlohmann::json&);
			std::string getTo() const;
			std::string getResult() const;	
			std::optional<double> getTimeout() const;
			Message getPrompt() const;
			SpecValue getChoices() const;
			void process(GameState&) override; 
			void parseRule(const nlohmann::json&);
		private:
			std::string to;	//represents field "to" in input choice rule
			Message prompt; 
			SpecValue choices;
			std::string result; //represents field "result" in input choice rule
			std::optional<double> timeout;
			
	};

}

#endif
