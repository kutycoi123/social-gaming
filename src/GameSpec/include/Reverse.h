#ifndef REVERSE_H
#define REVERSE_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include "GameState.h"


namespace GameSpecification{

    struct type{
        std::string a;
        int;
        bool;
        double;
        std::vector<ValueType>;
        std::unordered_map<std::string, ValueType> mapp;
    };

    struct Visit_Expression : public boost::static_visitor<>{
//        void operator()(int& existing) const {
//            // Do something
//            std::cout << "Int\n";
//        };
//        void operator()(double& d) const{
//            // Do something
//            std::cout << "Double Visitor\n";
//        };
//        void operator()(std::string& s) const{
//            std::cout << "std::string Visitor\n";
//        }
//        void operator()(bool& b) const{
//            std::cout << "Bool Visitor\n";
//        };
//        void operator()(std::vector<std::string>& sv) const{
//            std::cout << "String Vector Visitor\n";
//        };
//        void operator()(std::unordered_map<std::string, std::string>& um) const{
//            std::cout << "UMap Visitor\n";
//        };
//        void operator()(std::vector<ValueType>& vvt) const{
//            std::cout << "Unordered Variant Vector Visitor\n";
//        };

        type operator()(std::unordered_map<std::string, ValueType> const& umvt) const {
            type a;
            a.mapp = umvt;
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
