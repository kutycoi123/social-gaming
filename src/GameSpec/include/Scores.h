#ifndef SCORES_H
#define SCORES_H

#include "BaseRule.h"
#include "ControlStructRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Scores : public BaseRule{
    public:
		Scores();
        Scores(double score, bool ascending);
        double getScore() const;
        bool getAscending() const;
		void process(GameState&) override;
        void parseRule(const nlohmann::json&) override;
    private:
        double score;
        bool ascending;
};
}
#endif
