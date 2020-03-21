#include "Deal.h"
#include "DealVisitor.h"

using GameSpecification::Deal;
using GameSpecification::SpecValue;
using GameSpecification::BaseRule;
using json = nlohmann::json;
Deal::Deal() : BaseRule(RuleType::DealType), from(""), count(0){}

Deal::Deal(const json& ruleJson) : BaseRule(RuleType::DealType){
    parseRule(ruleJson);
}

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
    auto gameStateValueFrom = gameState.getVariable(from);
    
    if (auto fromList = gameStateValueFrom->lock()) {
        auto gameStateValueTo = gameState.getVariable(boost::get<std::string>(to.value));
        if (auto toList = gameStateValueTo->lock()) {
            std::shared_ptr<StateValueList> valueList;
            valueList = std::static_pointer_cast<StateValueList>(toList);

            DealVisitor visitor(getCount(), *valueList);
            fromList->accept(visitor);
        }
    }
}

void Deal::parseRule(const json& ruleJson){
    try{
        from = ruleJson.at("from").get<std::string>();
        count = ruleJson.at("count").get<int>();
        json to = ruleJson.at("to");
        if(to.is_string()){
            this->to.value = to.get<std::string>();
        } else{
            this->to.value = to.get<std::vector<std::string>>();
        }
        
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}