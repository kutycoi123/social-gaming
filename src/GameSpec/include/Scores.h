#ifndef SCORES_H
#define SCORES_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <string>
namespace GameSpecification{
class Scores : public BaseRule{
    public:
		Scores();
        Scores(const double score, const bool ascending);
        double getScore() const;
        bool getAscending() const;
		void process(GameState&) override;
    private:
        double score;
        bool ascending;
};
}
#endif
