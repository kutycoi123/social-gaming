#include "GlobalMessage.h"

using GameSpecification::GlobalMessage;
using json = nlohmann::json;

GlobalMessage::GlobalMessage(const std::string& value) : 
    BaseRule({}), 
    value(value){}

void GlobalMessage::process(GameState& gameState) {
    /*
    auto variables = gameState.getVariable(value);
    if (auto retrievedValue = variables->lock()) {
        // TODO: Finish global message visitor implementation
        GlobalMessageVisitor visitor{};
        retrievedValue->accept(visitor);
//        auto val = boost::apply_visitor(Visit_Type(), retrievedValue.get()->value);
//        if(val.i){
//            //add message to the game
//        }
//        if(val.str.size()>0){
//            //add message to the game
//        }
    }
    */
}