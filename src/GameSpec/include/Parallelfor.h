#ifndef PARALLELFOR_H
#define PARALLELFOR_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <string>
#include <vector>
namespace GameSpecification{
class Parallelfor : public ControlStructRule{
    public:
		Parallelfor();
        Parallelfor(std::vector<std::string> list, const std::string& element);
        std::vector<std::string> getList() const;
        std::string getElement() const;
		void process() override;        
    private:
        std::vector<std::string> list;
        std::string element;
};
}
#endif
