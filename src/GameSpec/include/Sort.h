#ifndef SORT_H
#define SORT_H

#include "BaseRule.h"
#include <string>
namespace GameSpecification{
class Sort : public BaseRule{
    public:
        Sort();
        Sort(const std::string& _list, const std::string& _list);
        std::string getList() const;
        std::string getKey() const;
       	void process() override; 
    private:
        std::string _list;
        std::string _key;
};
}
#endif

// sort, time, input text, input vote, globalmessage, score