#ifndef INPARALLEL_H
#define INPARALLEL_H

#include "BaseRule.h"
#include <string>
#include <vector>
namespace GameSpecification{
class Inparallel : public BaseRule{
    public:
        Inparallel(std::vector<std::string> rules);
        std::vector<std::string> getRules() const;
		void process() override;
    private:
        std::vector<std::string> _rules;
};
}
#endif
