#ifndef SCORES_H
#define SCORES_H

#include "BaseRule.h"
<<<<<<< HEAD
#include <nlohmann/json.hpp>
=======
#include "ControlStructRule.h"
>>>>>>> working on centralized parsing
#include <string>
namespace GameSpecification{
class Scores : public BaseRule{
    public:
        Scores(double score, bool ascending);
		void process(GameState&) override;
    private:
        double score;
        bool ascending;
};
}
#endif
