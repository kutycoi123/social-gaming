#ifndef INPARALLEL_H
#define INPARALLEL_H

#include "BaseRule.h"
<<<<<<< HEAD
#include <nlohmann/json.hpp>
=======
#include "ControlStructRule.h"
>>>>>>> working on centralized parsing
#include <string>
#include <vector>
namespace GameSpecification{
class Inparallel : public BaseRule{
    public:
        Inparallel();
        Inparallel(const nlohmann::json&);
		void process(GameState&) override;
    private:
};
}
#endif
