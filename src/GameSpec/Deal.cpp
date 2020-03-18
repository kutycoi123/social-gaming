#include "Deal.h"

using GameSpecification::Deal;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;
using json = nlohmann::json;
Deal::Deal() : BaseRule(RuleType::DealType), from(""), count(0){}

Deal::Deal(const std::string& from, const SpecValue& to, const int count) : BaseRule(RuleType::DealType), from(from), to(to), count(count){}

std::string Deal::getFrom() const{
    return from;
}

SpecValue Deal::getTo() const{
    return to;
}

int Deal::getCount() const{
    return count;
}

void Deal::process(GameState& gameState) {
	//TODO: Add code to process deal rule
}

void Deal::parseRule(const json& ruleJson){
    try{
        from = ruleJson.at("from").get<std::string>();
        count = ruleJson.at("count").get<int>();
        json to = ruleJson.at("to");
        if(to.is_string()){
            this->to.value = to.get<std::string>();
        }else{
            this->to.value = to.get<std::vector<std::string>>();
        }
        
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}