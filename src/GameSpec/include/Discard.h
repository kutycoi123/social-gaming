#ifndef DISCARD_H
#define DISCARD_H

#include "BaseRule.h"
#include <string>
namespace GameSpecification{
class Discard : public BaseRule{
    public:
        Discard();
        Discard(const std::string& from, const int count);
        std::string getFrom() const;
        int getCount() const;
       	void process() override; 
    private:
        std::string from;
        int count;
};
}
#endif
