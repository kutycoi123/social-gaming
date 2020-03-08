#ifndef REVERSE_H
#define REVERSE_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include "GameState.h"


namespace GameSpecification{

    struct Type{
        std::string str;
        int i;
        bool b;
        double d;
        std::vector<ValueType> vect;
        std::unordered_map<std::string, ValueType> map;
    };

    struct Visit_Type : public boost::static_visitor<Type>{

        Type operator()(int& existing) const {
            Type a;
            a.i = existing;
            return a;

        };

        Type operator()(double& d) const{
            Type a;
            a.d = d;
            return a;
        };

        Type operator()(std::string& s) const{
            Type a;
            a.str = s;
            return a;
        };

        Type operator()(bool& b) const{
            Type a;
            a.b = b;
            return a;
        };

        Type operator()(std::vector<ValueType>& vvt) const{
            Type a;
            a.vect = vvt;
            return a;
        };

        Type operator()(std::unordered_map<std::string, ValueType> const& umvt) const {
            Type a;
            a.map = umvt;
            return a;
        };
    };
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
