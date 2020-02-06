#ifndef REVERSE.H
#define REVERSE.H

#include "rule.h"
#include <string>

class Reverse : public Rule{
    public:
        Reverse();
        Reverse(const std::string& list);
        std::string getList() const;
        void setList(const std::string& list);
    private:
        std::string _list;
};

#endif