#ifndef DISCARD_H
#define DISCARD_H

#include "Rule.h"
#include <string>

class Discard : public Rule{
    public:
        Discard();
        Discard(const std::string& from, const int count);
        std::string getFrom() const;
        int getCount() const;
        void setFrom(const std::string& from);
        void setCount(const int count);
    private:
        std::string _from;
        int _count;
};

#endif