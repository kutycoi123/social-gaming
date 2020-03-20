#ifndef GLOBALMESSAGE_H
#define GLOBALMESSAGE_H

#include "BaseRule.h"
namespace GameSpecification{
class GlobalMessage : public BaseRule{
    public:
        GlobalMessage(const std::string& value);
		
        void process(GameState&) override;

    private:
      std::string value;
};
}
#endif
