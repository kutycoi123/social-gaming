#ifndef INPUTTEXT_H
#define INPUTTEXT_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class InputText : public BaseRule{
    public:
		InputText();
		InputText(const nlohmann::json&);
		std::string getUser() const;
		std::string getPrompt() const;
		std::string getResult() const;
		double getTimeOut() const;
		void process(GameState&) override;
		void parseRule(const nlohmann::json&);
    private:
        std::string user;
        std::string prompt;
        std::string result;
        double timeout;
};
}
#endif
