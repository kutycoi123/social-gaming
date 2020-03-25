#ifndef INPUTCHOICERULE_H
#define INPUTCHOICERULE_H

#include "GameSpec.h"

namespace GameSpecification{

	class InputChoice: public BaseRule{
		public:
			InputChoice(std::string , std::string , const std::shared_ptr<StateValue>&, std::string , double);
			void process(GameState&) override; 

		private:
			std::string to;	//represents field "to" in input choice rule
			std::string prompt; 
			std::weak_ptr<StateValue> choices;
			std::string result; //represents field "result" in input choice rule
			std::optional<double> timeout;
			
	};

}

#endif
