#ifndef GLOBALMESSAGE_H
#define GLOBALMESSAGE_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class GlobalMessage : public BaseRule{
    public:
		GlobalMessage();
    GlobalMessage(const std::string& value);
    std::string getValue() const;
		void process(GameState&) override;
    void parseRule(const nlohmann::json&) override;
    private:
        std::string value;
};
}
#endif
