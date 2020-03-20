#ifndef PARALLELFOR_H
#define PARALLELFOR_H

#include "BaseRule.h"
<<<<<<< HEAD
#include <nlohmann/json.hpp>
=======
#include "ControlStructRule.h"
>>>>>>> working on centralized parsing
#include <string>
#include <vector>
namespace GameSpecification{
class Parallelfor : public BaseRule{
    public:
        Parallelfor(std::vector<std::string> list, const std::string& element);

        void process(GameState&) override;        
    private:
        std::vector<std::string> list;
        std::string element;
};
}
#endif
