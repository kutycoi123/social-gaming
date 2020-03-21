
#include "GameParser.h"

using GameSpecification::stringToRuleType;
using GameSpecification::ForEach;
using GameSpecification::Inparallel;
using GameSpecification::Loop;
using GameSpecification::Parallelfor;
using GameSpecification::RuleType;

////public methods
GameParser::GameParser(const std::string& path){

    nlohmann::json gameJson = fileToJson(path);
    parseEntireGameJson(gameJson);
    GameState gameState;
    game = std::make_unique<Game> (Game(getGameSpecifications(), gameState));
}

std::unique_ptr<Game> GameParser::getGame() noexcept{
    return std::move(game);
}
//////private methods /createsession RockPaperScissors
void GameParser::parseEntireGameJson(const nlohmann::json& gameJson) {

    //StatusCode status = validGameJson(gameJson);

    if (true) {
        for (auto& [key, value] : gameJson.items()) {
            std::string jsonKey = key;
            auto enumKey = jsonGameSpecification.find(jsonKey);
            auto test4 = gameJson.at(CONFIGURATION_STRING);
            switch(enumKey->second) {
                case RULES:
                    parseRules(value);
                    break;
                case CONFIGURATION:
                    parseConfiguration(value);
                    break;
                case CONSTANTS:
                    setConstants(value);
                    break;
                case VARIABLES:
                    setVariables(value);
                    break;
                case PER_PLAYER:
                    setPerPlayer(value);
                    break;
                case PER_AUDIENCE:
                    setPerAudience(value);
                    break;
                default:
                    assert(false);
            }
        }
    }

}
     
void GameParser::parseConfiguration(const nlohmann::json & configs) {

    //validateConfiguration(configs);
    this->configSettings.name = configs.at(NAME);
    this->configSettings.audience = configs.at(AUDIENCE);
    this->configSettings.maxPlayercount = configs.at(PLAYER_COUNT).at(MAX);
    this->configSettings.minPlayercount = configs.at(PLAYER_COUNT).at(MIN);
    this->configSettings.setup = configs.at(SETUP);
}
  // END-TODO



void GameParser::parseRules(const nlohmann::json& rules) {
    for (auto& [key, value] : rules.items()) {

        std::string jsonKey = key;
        GameSpecification::RuleType ruleType = GameSpecification::stringToRuleType[jsonKey];

        auto baseRulePtr = GameSpecification::getRulePtrFromRuleType(ruleType, value);
        if(!baseRulePtr){
            switch(ruleType){

                case RuleType::ForEachType:
                    baseRulePtr = std::shared_ptr<BaseRule>(new ForEach(value));
                    break;
                case RuleType::InparallelType:
                    baseRulePtr = std::shared_ptr<BaseRule>(new Inparallel(value));
                    break;
                case RuleType::LoopType:
                    baseRulePtr = std::shared_ptr<BaseRule>(new Loop(value));
                    break;
                case RuleType::ParallelforType:
                    baseRulePtr = std::shared_ptr<BaseRule>(new Parallelfor(value));
                    break;
                default:
                    continue;
            }
        }

        this->gameSpecifications.addRule(baseRulePtr);
    }

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

 
GameParser::StatusCode GameParser::validGameJson(const nlohmann::json& jsonObject){

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

GameParser::StatusCode GameParser::validateConfiguration(const nlohmann::json& config){

    auto i = std::find_if(config.items().begin(), config.items().end(), [&](auto& elem){
        return (jsonGameConfiguration.find(elem.key()) == jsonGameConfiguration.end()) ;
    });

    if (i != config.items().end()){
        return StatusCode::INVALID;
    }
    if(validatePlayerNumber(const_cast<json &>(config)) != StatusCode::VALID){
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
 
 
GameParser::StatusCode GameParser::validateRules(const nlohmann::json& incomingRules) {
	
    auto result = std::find_if(incomingRules.items().begin(), incomingRules.items().end(), [&](auto& elem){
        return stringToRuleType.find(elem.key()) == stringToRuleType.end();
    });


    if (result == incomingRules.items().end()) {
        return StatusCode::INVALID;
    }
	
    return StatusCode::VALID;
}

nlohmann::json GameParser::fileToJson(const std::string& pathName) {
    std::ifstream ifs(pathName);
    nlohmann::json JsonConfig = nlohmann::json::parse(ifs);
    return JsonConfig;
}

const GameSpecification::GameSpec &GameParser::getGameSpecifications() const {
    return gameSpecifications;
}
