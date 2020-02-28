#include <iostream>
#include <map>
#include "include/GameParser.h"

#include "BaseRule.h"


GameParser::GameParser() {};

StatusCode GameParser::validGameJson(std::string& jsonstr){
    nlohmann::json jsonObject = nlohmann::json::parse(jsonstr);
    size_t jsonGameSpecificationMapSize = jsonGameSpecification.size();
    if(jsonGameSpecificationMapSize!=jsonObject.size())
    {
        return StatusCode::INVALID;
    }
    auto i = std::find_if(jsonObject.items().begin(), jsonObject.items().end(), [&](auto& elem){
        return (jsonGameSpecification.find(elem.key()) == jsonGameSpecification.end()) ;
    });
    if (i != jsonObject.items().end()){
        return StatusCode::INVALID;
    }
    if(validateConfiguration(jsonObject) != StatusCode::VALID){
        return StatusCode::INVALID;
    }
    return StatusCode::VALID;
}

StatusCode GameParser::validateConfiguration(nlohmann::json& json){
    nlohmann::json config = json.at(CONFIGURATION);
    auto i = std::find_if(config.items().begin(), config.items().end(), [&](auto& elem){
        return (jsonGameConfiguration.find(elem.key()) == jsonGameConfiguration.end()) ;
    });

    if (i != config.items().end()){
        return StatusCode::INVALID;
    }
    if(validatePlayerNumber(config) != StatusCode::VALID){
        return StatusCode::INVALID;
    }
    return StatusCode::VALID;
}


StatusCode GameParser::validatePlayerNumber(nlohmann::json& jsonObject){
    nlohmann::json player = jsonObject.at(PLAYER_COUNT);
    nlohmann::json minPlayerCount = player.at(MIN);
    nlohmann::json maxPlayerCount = player.at(MAX);

    if(minPlayerCount.type_name() != NUMBER || maxPlayerCount.type_name() != NUMBER){
        return StatusCode::INVALID;
    }
    if(maxPlayerCount < 0 || minPlayerCount < 0){
        return StatusCode::INVALID;
    }
    if(maxPlayerCount < minPlayerCount){
        return StatusCode::INVALID;
    }
    return StatusCode::VALID;
}

StatusCode GameParser::rulesValidation(const nlohmann::json& incomingRules) {
    auto ruleMap = GameSpecification::BaseRule::rulemap;

    auto result = std::find_if(incomingRules.items().begin(), incomingRules.items().end(), [&](auto& elem){
        return ruleMap.find(elem.key()) == ruleMap.end();
    });

    if (result == incomingRules.items().end()) {
        return StatusCode::INVALID;
    }

    return StatusCode::VALID;
}

nlohmann::json GameParser::fileToJson(const std::string& pathName) {
    std::ifstream i(pathName);
    nlohmann::json JsonConfig;
    i >> JsonConfig;
    return JsonConfig;
}