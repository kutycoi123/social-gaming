#ifndef FOREACH_H
#define FOREACH_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <string>
#include <vector>
namespace GameSpecification{
class ForEach : public BaseRule{
    public:
        ForEach();
        ForEach(const SpecValue& list, const std::string& element, std::vector<std::string>& rules);
        SpecValue getList() const;
        std::string getElement() const;
        std::vector<std::string> getRules() const;
       	void process() override; 
    private:
        //spec value take all value
        SpecValue _list;
        std::string _element;
        std::vector<std::string> _rules;
};
}
#endif
