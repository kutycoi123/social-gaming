#ifndef EXTEND_H
#define EXTEND_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Extend : public BaseRule{
    public:
        Extend();
        Extend(const std::string& target, const SpecValue& list);
        std::string getTarget() const;
        SpecValue getList() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&) override;
    private:
        std::string target;
        SpecValue list;
};
}
#endif
