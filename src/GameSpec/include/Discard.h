#ifndef DISCARD_H
#define DISCARD_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Discard : public BaseRule{
    public:
        Discard();
        Discard(const nlohmann::json&);
        std::string getFrom() const;
        int getCount() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&);
    private:
        std::string from;
        int count;
};
}
#endif
