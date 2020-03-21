#ifndef ADD_H
#define ADD_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Add : public BaseRule{
    public:
        Add();
        Add(const nlohmann::json&);
        std::string getTo() const;
        SpecValue getValue() const;
		void process(GameState&) override;
        void parseRule(const nlohmann::json&);
        int determineAmountToAdd(const SpecValue &, GameState &);
    private:
        std::string to;
        SpecValue value;
};
}
#endif
