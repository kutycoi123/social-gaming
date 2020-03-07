#include "Add.h"
#include <boost/variant/apply_visitor.hpp>
#include <iostream>

using GameSpecification::Add;
using GameSpecification::SpecValue;
using json = nlohmann::json;

Add::Add() : BaseRule(RuleType::AddType), to(""){}

Add::Add(const std::string& to, const SpecValue& value) 
    : BaseRule(RuleType::AddType), to(to), value(value){}

std::string Add::getTo() const{
    return to;
}
SpecValue Add::getValue() const{
    return value;
}

class AddVisitor : public boost::static_visitor<>{
    public:
    void operator()(int& existing) const {
        std::cout << "Int\n";
    }
    void operator()(double& d) const{
        std::cout << "Double Visitor\n";
    }
    void operator()(std::string& s) const{
        std::cout << "std::string Visitor\n";
    }
    void operator()(bool& b) const{
        std::cout << "Bool Visitor\n";
    }
    void operator()(std::vector<std::string>& sv) const{
        std::cout << "String Vector Visitor\n";
    }
    void operator()(std::unordered_map<std::string, std::string>& um) const{
        std::cout << "UMap Visitor\n";
    }
    void operator()(std::vector<ValueType>& vvt) const{
        std::cout << "Unordered Variant Vector Visitor\n";
    }
    void operator()(std::unordered_map<std::string, ValueType>& umvt) const{
        std::cout << "Unordered Variant Map Visitor\n";
    }
};

void Add::process(GameState& gameState){
    // TODO: Find a better way to wrap and unwrap boost variant
    // TODO: Handle cases not just for int
    auto a = gameState.getVariable(to);
    if (!a.has_value()){
        return;
    }

    if (auto retrievedValue = a->lock()) {
        auto existingValue = this->value.value;

        auto newValue = retrievedValue->value;
        // retrievedValue->value = newValue + existingValue;
        
        boost::apply_visitor(AddVisitor(), existingValue);
    }

}
void Add::parseRule(const json& ruleJson){
    try{

    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}