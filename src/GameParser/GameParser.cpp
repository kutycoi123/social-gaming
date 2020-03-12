
#include "GameParser.h"

using GameSpecification::stringToRuleType;
GameParser::GameParser() {};

void GameParser::parseEntireGameJson(const nlohmann::json& gameJson) {
    for (auto& fields : gameJson.items()) {

        std::string jsonKey = fields.key();
        auto enumKey = jsonGameSpecification.find(jsonKey);
        switch(enumKey->second) {
            case CONFIGURATION:
                parseConfiguration(fields.value());
                break;
            case RULES:
                parseRules(fields.value());
                break;
            case CONSTANTS:
                setConstants(fields.value());
                break;
            case VARIABLES:
                setVariables(fields.value());
                break;
            case PER_PLAYER:
                setPerPlayer(fields.value());
                break;
            case PER_AUDIENCE:
                setPerAudience(fields.value());
                break;
            default:
                assert(false);
        }
    }
}

     
void GameParser::parseConfiguration(const nlohmann::json& configs) {
  // TODO: Refactor based on Hunars changes for validating game configurations
    validateConfiguration(configs);
    this->configSettings.name = configs["name"];
    this->configSettings.audience = configs["audience"];
    this->configSettings.maxPlayercount = configs["player count"]["max"];
    this->configSettings.minPlayercount = configs["player count"]["in"];
    this->configSettings.setup = configs["setup"];
    //TODO: integrate with GeneralGameConfigClass
}
  // END-TODO



void GameParser::parseRules(const nlohmann::json& rule) {

    GameSpecification::RuleType ruleType = stringToRuleType.at(rule.at("rule").get<std::string>());
    std::shared_ptr<GameSpecification::BaseRule> baseRulePtr = GameSpecification::getRulePtrFromRuleType(rule);
	baseRulePtr->parseRule(rule);
	this->gameSpecifications.addRule(baseRulePtr);

}



void GameParser::setConstants(const nlohmann::json& constants) {
    this->constants = constants;
}
void GameParser::setVariables(const nlohmann::json& variables) {
    this->variables = variables;
}
void GameParser::setPerPlayer(const nlohmann::json& perPlayer) {
    this->perPlayer = perPlayer;
}

void GameParser::setPerAudience(const nlohmann::json& perAudience) {
    this->perAudience = perAudience;
}

 
GameParser::StatusCode GameParser::validGameJson(std::string& jsonstr){
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

GameParser::StatusCode GameParser::validateConfiguration(const nlohmann::json& json){
    nlohmann::json config = json.at(CONFIGURATION_STRING);
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


GameParser::StatusCode GameParser::validatePlayerNumber(nlohmann::json& jsonObject){
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
 
 
GameParser::StatusCode GameParser::rulesValidation(const nlohmann::json& incomingRules) {
	
    auto result = std::find_if(incomingRules.items().begin(), incomingRules.items().end(), [&](auto& elem){
        return stringToRuleType.find(elem.key()) == stringToRuleType.end();
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

const GameSpecification::GameSpec &GameParser::getGameSpecifications() const {
    return gameSpecifications;
}
