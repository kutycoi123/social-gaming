#ifndef CASE_H
#define CASE_H

#include "BaseRule.h"
#include <string>
namespace GameSpecification{
class Case : BaseRule{
    public:
        Case();
<<<<<<< HEAD
        Case(const nlohmann::json&);
        std::string getValue();
        void process(GameState&) override;
        void parseRule(const nlohmann::json&);
=======
        Case(const std::string& value, const std::vector<BaseRule>&);
//        std::string getValue();
  //      std::vector<BaseRule> getRules() const;
    //    std::string getValue();
>>>>>>> working on centralized parsing
    private:
        std::string value;
};
}
#endif
