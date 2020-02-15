#ifndef TIMER_H
#define TIMER_H

#include "BaseRule.h"
#include <string>
namespace GameSpecification{
class Timer : public BaseRule{
    public:
        Timer();
        Timer(const double duration, const std::string& mode, const bool flag);
        double getDuration() const;
        std::string getMode() const;
        bool getFlag() const;
       	void process() override; 
    private:
        double _duration;
        std::string _mode;
        bool _flag;
};
}
#endif
