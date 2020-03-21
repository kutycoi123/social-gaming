#include "Add.h"
#include "AddVisitor.h"

using GameSpecification::Add;
using GameSpecification::SpecValue;
using json = nlohmann::json;

Add::Add(const json& ruleJson) : BaseRule(RuleType::AddType) {
    parseRule(ruleJson);
}

std::string Add::getTo() const{
    return to;
}
SpecValue Add::getValue() const{
    return value;
}

void Add::process(GameState& gameState){
    auto gameStateValue = gameState.getVariable(to);
    if (auto retrievedValue = gameStateValue->lock()) {
        // TODO: Finish add visitor implementation
        AddVisitor visitor;
        retrievedValue->accept(visitor);
    }

//
//    if (auto gsValue = gameStateValue->lock()) {
//        auto existingValue = gsValue->value;
//        int v1 = boost::get<int>(existingValue);
//
//        auto addedValue = getValue().value;
//        auto test = boost::get<std::string>(addedValue);
//
//        // Determine if value is int or string
//        int type = addedValue.which();
//        int v2 = 0;
//
//        // TODO: Find potential way to handle type checking better
//        if (type == 1) {
//            v2 = boost::get<int>(addedValue);
//        } else {
//            auto variableToAdd = gameState.getVariable(boost::get<std::string>(addedValue));
//            auto constantToAdd = gameState.getConstant(boost::get<std::string>(addedValue));
//
//            if (variableToAdd.has_value()) {
//                auto vValue = variableToAdd->lock();
//                v2 = boost::get<int>(vValue->value);
//            }
//
//            if (constantToAdd.has_value()) {
//                auto cValue = variableToAdd->lock();
//                v2 = boost::get<int>(cValue->value);
//            }
//        }
//
//        gsValue->value = v1 + v2;
//    }

}
void Add::parseRule(const json& ruleJson){
    try{
        to = ruleJson.at("to").get<std::string>();
    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}