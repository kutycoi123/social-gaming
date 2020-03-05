#ifndef SHUFFLE_H
#define SHUFFLE_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Shuffle :public BaseRule{
    public:
        Shuffle();
        Shuffle(const std::string& list);
        std::string getList() const;
		void process(GameState&) override;
        void parseRule(const nlohmann::json&) override;
    private:
        std::string list;
        std::string key;
};
}
#endif
