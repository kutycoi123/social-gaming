#ifndef SCORES_H
#define SCORES_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
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
