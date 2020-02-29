#ifndef GLOBALMESSAGE_H
#define GLOBALMESSAGE_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <string>
namespace GameSpecification{
class GlobalMessage : public BaseRule{
    public:
		GlobalMessage();
        GlobalMessage(const std::string& value);
        std::string getValue() const;
		void process(GameState&) override;
    private:
        std::string value;
};
}
#endif
