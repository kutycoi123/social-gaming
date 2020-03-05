#ifndef DISCARD_H
#define DISCARD_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
namespace GameSpecification{
class Discard : public BaseRule{
    public:
        Discard();
        Discard(const std::string& from, const int count);
        std::string getFrom() const;
        int getCount() const;
       	void process(GameState&) override; 
        void parseRule(const nlohmann::json&) override;
    private:
        std::string from;
        int count;
};
}
#endif
