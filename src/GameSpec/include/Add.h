#ifndef ADD_H
#define ADD_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <string>
namespace GameSpecification{
class Add : public BaseRule{
    public:
        Add();
        Add(const std::string& to, const SpecValue& value);
        std::string getTo() const;
        SpecValue getValue() const;
		void process(GameState&) override;
    private:
        std::string to;
        SpecValue value;
};
}
#endif
