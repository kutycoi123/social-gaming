#ifndef DEAL_H
#define DEAL_H

#include "BaseRule.h"
#include "AbstractSpec.h"
#include <string>
namespace GameSpecification{
class Deal : public BaseRule{
    public:
        Deal();
        Deal(const std::string& from, const SpecValue& to, const int count);
        std::string getFrom() const;
        SpecValue getTo() const;
        int getCount() const;
        void setFrom(const std::string& from);
        void setTo(const SpecValue& to);
        void setCount(const int count);
    private:
        std::string _from;
        SpecValue _to;
        int _count;
};
}
#endif
