#include "Reverse.h"

using GameSpecification::Reverse;
using GameSpecification::BaseRule;
using json = nlohmann::json;
Reverse::Reverse() : BaseRule("reverse"), list(""){}

Reverse::Reverse(const std::string& list) : BaseRule("reverse"), list(list) {}

std::string Reverse::getList() const{
    return list;
}

void Reverse::process(GameState& gameState) {
	//TODO: Add code to process reverse rule
}

void Reverse::parseRule(const nlohmann::json& json){
    try{

    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}