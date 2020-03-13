#ifndef REVERSE_H
#define REVERSE_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include "GameState.h"


namespace GameSpecification{

class Reverse : public BaseRule{
    public:
        std::string operator()(std::string const& str){
            std::string string = str;
            return string;
        }
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
