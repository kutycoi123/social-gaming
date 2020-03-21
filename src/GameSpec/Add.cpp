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
        int amount = determineAmountToAdd(getValue(), gameState);

        AddVisitor visitor(amount);
        retrievedValue->accept(visitor);
    }
}

void Add::parseRule(const json& ruleJson){
    try{
        to = ruleJson.at("to").get<std::string>();
    }catch(json::exception &e){
        std::cout << e.what() << "\n";
    }
}

int Add::determineAmountToAdd(const SpecValue& specValue, GameState& gameState) {
    auto addedValue = getValue().value;
    int type = addedValue.which();
    if (type == 1) {
        return boost::get<int>(addedValue);
    } else {
        auto variableToAdd = gameState.getVariable(boost::get<std::string>(addedValue));
        auto constantToAdd = gameState.getConstant(boost::get<std::string>(addedValue));

        if (variableToAdd.has_value()) {
            auto vValue = variableToAdd->lock();

            std::shared_ptr<StateValueNumber> valueNumber;
            valueNumber = std::static_pointer_cast<StateValueNumber>(vValue);
            return valueNumber->getValue();
        }

        if (constantToAdd.has_value()) {
            auto cValue = variableToAdd->lock();

            std::shared_ptr<StateValueNumber> valueNumber;
            valueNumber = std::static_pointer_cast<StateValueNumber>(cValue);
            return valueNumber->getValue();
        }
    }
    
    return 0;
}