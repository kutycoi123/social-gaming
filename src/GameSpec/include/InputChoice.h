#ifndef INPUTCHOICERULE_H
#define INPUTCHOICERULE_H

#include "GameSpec.h"
#include "Message.h"
#include <nlohmann/json.hpp>

namespace GameSpecification{
	class InputChoice: public BaseRule{
		
		public:
			InputChoice() : BaseRule(RuleType::InputChoiceType) {}
			InputChoice(const std::string& to, const Message& prompt, const SpecValue& choices, 
							const std::string& result, double timeout) 
							:  BaseRule(RuleType::InputChoiceType), to(to), prompt(prompt), choices(choices), 
							   result(result), timeout(timeout) {}
			std::string getTo() const;
			std::string getResult() const;	
			std::optional<double> getTimeout() const;
			Message getPrompt() const;
			SpecValue getChoices() const;
			void process(GameState&) override; 
			void parseRule(const nlohmann::json&) override;
		private:
			std::string to;	//represents field "to" in input choice rule
			Message prompt; 
			SpecValue choices;
			std::string result; //represents field "result" in input choice rule
			std::optional<double> timeout;
			
	};

}

#endif
