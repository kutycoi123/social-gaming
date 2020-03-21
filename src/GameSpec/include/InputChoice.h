#ifndef INPUTCHOICERULE_H
#define INPUTCHOICERULE_H

#include "GameSpec.h"

namespace GameSpecification{

	class InputChoice: public BaseRule{
		public:
			InputChoice(const std::string&, const std::string&, const SpecValue&, const std::string&, double);
			void process(GameState&) override; 

		private:
			std::string to;	//represents field "to" in input choice rule
			std::string prompt; 
			SpecValue choices;
			std::string result; //represents field "result" in input choice rule
			std::optional<double> timeout;
			
	};

}

#endif
