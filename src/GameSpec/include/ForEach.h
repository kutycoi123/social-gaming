#ifndef FOREACH_H
#define FOREACH_H

#include "AbstractSpec.h"
#include "ControlStructRule.h"
#include <string>
#include <vector>
namespace GameSpecification{
class ForEach : public ControlStructRule{
    public:
        ForEach();
        ForEach(const SpecValue& list, const std::string& element);
        SpecValue getList() const;
        std::string getElement() const;
       	void process(GameState&) override; 
    private:
        //spec value take all value
        SpecValue list;
        std::string element;
};
}
#endif
