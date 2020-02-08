#ifndef EXTEND_H
#define EXTEND_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <string>
namespace GameSpecification{
class Extend : public BaseRule{
    public:
        Extend();
        Extend(const std::string& target, const SpecValue& list);
        std::string getTarget() const;
        SpecValue getList() const;
        void setTarget(const std::string& target);
        void setList(const SpecValue& list);
    private:
        std::string _target;
        SpecValue _list;
};
}
#endif
