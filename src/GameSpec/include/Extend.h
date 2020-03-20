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
        Extend(const nlohmann::json&);
        std::string getTarget() const;
        SpecValue getList() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&);
    private:
        std::string target;
        SpecValue list;
};
}
#endif
