#ifndef ADD.H
#define ADD.H

#include "rule.h"
#include "GameSpec.h"
#include <string>

class Add : public Rule{
    public:
        Add();
        Add(const std::string& to, const SpecValue& value);
        std::string getTo() const;
        SpecValue getValue() const;
        void setTo(const std::string& to);
        void setValue(const SpecValue& value);
    private:
        std::string _to;
        SpecValue _value;
};

#endif