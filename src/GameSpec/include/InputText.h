#ifndef INPUTTEXT_H
#define INPUTTEXT_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <string>
namespace GameSpecification{
class InputText : public BaseRule{
    public:
		InputText();
        InputText(const User& user, const std::string& prompt);
        User getUser() const;
        std::string getPrompt() const;
        std::string getResult() const;
        double getTimeOut() const;
		void process() override;
    private:
        User _user;
        std::string _prompt;
        std::string _result;
        double _timeout
};
}
#endif
