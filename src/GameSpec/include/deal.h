#ifndef DEAL.H
#define DEAL.H

#include "rule.h"
#include "GameSpec.h"
#include <string>

class Deal : public Rule{
    public:
        Deal();
        Deal(const std::string& from, const SpecValue& to, const int count);
        std::string getFrom() const;
        SpecValue getTo() const;
        int getCount() const;
        void setFrom(const std::string& from);
        void setTo(cosnt SpecValue& to);
        void setCount(const int count);
    private:
        std::string _from;
        SpecValue _to;
        int _count;
};

#enif