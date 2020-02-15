#ifndef TIMER_H
#define TIMER_H

#include "BaseRule.h"
#include <string>
namespace GameSpecification{
class Timer : public BaseRule{
    public:
        Timer();
        Timer(const double duration, const std::string& mode, const bool flag);
        double getDuration(0 const);
        std::string getDuration() const;
        double getFlag();
       	void process() override; 
    private:
        double _duration;
        std::string _mode;
        bool _flag;
};
}
#endif

// sort, time, input text, input vote, globalmessage, score