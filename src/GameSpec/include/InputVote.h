#ifndef INPUTVOTE_H
#define INPUTVOTE_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class InputVote : public BaseRule{
  	public:
  		InputVote();
		InputVote(const nlohmann::json&);
		std::string getUser() const;
		std::string getPrompt() const;
		std::string getChoice() const;
		std::string getResult() const;
		double getTimeOut() const;
    	void process(GameState&) override;
		void parseRule(const nlohmann::json&);
	private:
		std::string user;
		std::string prompt;
		std::string choices;
		std::string result;
		double timeout;
};
}
#endif
