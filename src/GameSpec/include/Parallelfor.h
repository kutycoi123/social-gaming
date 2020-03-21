#ifndef PARALLELFOR_H
#define PARALLELFOR_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
namespace GameSpecification{
class Parallelfor : public BaseRule{
    public:
        Parallelfor();
        Parallelfor(const nlohmann::json&);
        std::vector<std::string> getList() const;
        std::string getElement() const;
        void process(GameState&) override;        
        void parseRule(const nlohmann::json&);
    private:
        std::vector<std::string> list;
        std::string element;
};
}
#endif
