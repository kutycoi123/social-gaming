#ifndef SHUFFLE_H
#define SHUFFLE_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Shuffle :public BaseRule{
    public:
        Shuffle();
        Shuffle(const nlohmann::json&);
        std::string getList() const;
		void process(GameState&) override;
    private:
        std::string list;
        void parseRule(const nlohmann::json&);
};
}
#endif
