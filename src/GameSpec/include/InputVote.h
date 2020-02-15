#ifndef INPUTVOTE_H
#define INPUTVOTE_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <string>
namespace GameSpecification{
class InputVote : public BaseRule{
    public:
		InputVote();
        InputVote(const User& user,const std::string& prompt, const std::string& choices, const std::string& result, const double timeout);
        std::vector<User> getUser() const;
        std::string getPrompt() const;
        std::string getChoice() const;
        std::string getResult() const;
        double getTimeOut() const;
		void process() override;
    private:
        std::vector<User> _user;
        std::string _prompt;
        std::string _choices;
        std::string _result;
        double _timeout
};
}
#endif
