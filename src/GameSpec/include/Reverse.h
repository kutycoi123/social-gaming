#ifndef REVERSE_H
#define REVERSE_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Reverse : public BaseRule{
    public:
        Reverse();
        Reverse(const std::string& list);
        std::string getList() const;
		void process(GameState&) override;
        void parseRule(const nlohmann::json&) override;
    private:
        std::string list;
};
}
#endif
