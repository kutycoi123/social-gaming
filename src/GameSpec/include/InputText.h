#ifndef INPUTTEXT_H
#define INPUTTEXT_H

#include "BaseRule.h"
<<<<<<< HEAD
#include <nlohmann/json.hpp>
=======
#include "ControlStructRule.h"
>>>>>>> working on centralized parsing
#include <string>
namespace GameSpecification{
class InputText : public BaseRule{
    public:
		InputText(const std::string& user, const std::string& prompt, const std::string& result, const double timeout);

		void process(GameState&) override;

    private:
        std::string user;
        std::string prompt;
        std::string result;
        double timeout;
};
}
#endif
