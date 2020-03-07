#ifndef FOREACH_H
#define FOREACH_H

#include "AbstractSpec.h"
#include "ControlStructRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
namespace GameSpecification{
class ForEach : public BaseRule{
    public:
        ForEach();
        ForEach(const SpecValue& list, const std::string& element);
        SpecValue getList() const;
        std::string getElement() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&) override;
    private:
        //spec value take all value
        SpecValue list;
        std::string element;
};
}
#endif
