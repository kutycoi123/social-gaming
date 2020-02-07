#ifndef EXTEND.H
#define EXTEND.H

#include "Rule.h"
#include "GameSpec.h"
#include <string>

class Extend : public Rule{
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

#endif