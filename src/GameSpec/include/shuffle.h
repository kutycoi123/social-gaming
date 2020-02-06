#ifndef SHUFFLE.H
#define SHUFFLE.H

#include "rule.h"
#include <string>

class Shuffle :public Rule{
    public:
        Shuffle();
        Shuffle(const std::string& list);
        std::string getList() const;
        void setList(const std::string& list);
    private:
        std::string _list;
};

#endif