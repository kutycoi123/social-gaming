#include <iostream>
#include "include/GameParser.h"
#include "BaseRule.h"

GameParser::GameParser() {};


void GameParser::parseEntireGameJson(const nlohmann::json& gameJson) {

    for (nlohmann::json::iterator fields = gameJson.begin(); fields != gameJson.end(); ++fields) {
        std::string jsonKey = fields.key();
        auto enumKey = gameJsonMap.find(jsonKey);
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
            case PERPLAYER:
                setPerPlayer(fields.value());
                break;
            case PERAUDIENCE:
                setPerAudience(fields.value());
                break;
            default:
                assert(false);
        }
    }
}

     
void GameParser::parseConfiguration(const nlohmann::json& configs) {
  // TODO: Refactor based on Hunars changes for validating game configurations
    configValidator(configs);
    this->configSettings.name = configs["name"];
    this->configSettings.audience = configs["audience"];
    this->configSettings.maxPlayercount = configs["player count"]["max"];
    this->configSettings.minPlayercount = configs["player count"]["in"];
    this->configSettings.setup = configs["setup"];
    //TODO: integrate with GeneralGameConfigClass
}
  // END-TODO
 
void GameParser::handleOtherFields(const std::string& nonRules) {
  //TODO: create tables and classes for non rules in json. 
}


void GameParser::processRuleField(const std::string& singleRule) {
    auto ruleMap = GameSpecification::BaseRule::rulemap;
    GameSpecification::RuleType rule = ruleMap[singleRule];
    switch(rule) {

      case GameSpecification::RuleType::ForEachType:
        break;
      case GameSpecification::RuleType::LoopType:
        break;
      case GameSpecification::RuleType::InparallelType:
        break;
      case GameSpecification::RuleType::ParallelforType:
        break;
      case GameSpecification::RuleType::SwitchType:
        break;
      case GameSpecification::RuleType::WhenType:
        break;
      case GameSpecification::RuleType::ExtendType:
        break;
      case GameSpecification::RuleType::ReverseType:
        break;
      case GameSpecification::RuleType::ShuffleType:
        break;
      case GameSpecification::RuleType::SortType:
        break;
      case GameSpecification::RuleType::DealType:
        break;
      case GameSpecification::RuleType::DiscardType:
        break;
      case GameSpecification::RuleType::TimerType:
        break;
      case GameSpecification::RuleType::InputChoiceType:
        break;
      case GameSpecification::RuleType::InputTextType:
        break;
      case GameSpecification::RuleType::InputVoteType:
        break;
      case GameSpecification::RuleType::ScoresType:
        break;
      default:
        assert(false);

    }
}

void GameParser::parseRules(const nlohmann::json& rules) {
    //if (GameParser::rulesValidation(rules) == StatusCode::VALID) {
        for (nlohmann::json::iterator field = rules.begin(); field != rules.end(); ++field) {
            //TODO: use debugger to check the fields
            if( field->find("rules")!= field->end() || field->find("cases")!= field->end()) {
                parseRules(field.value());

            }else if (field->find("rule") != field->end()) {
                processRuleField(field.value());
                
            }else {
                handleOtherFields(field.value());
            }
        }
    //}  
}

void GameParser::setConstants(const nlohmann::json& constants) {
    this->constants = constants;
}
void GameParser::setVariables(const nlohmann::json& variables) {
    this->variables = variables;
}
void GameParser::setPerPlayer(const nlohmann::json& perPlayer) {
    this->perAudience = perPlayer;
}

void GameParser::setPerAudience(const nlohmann::json& perAudience) {
    this->perAudience = perAudience;
}

// TODO: Refactor based on Hunars changes for validating game configurations
void GameParser::configValidator(const nlohmann::json& configs){
    assert(configs.contains("configuration"));
    assert(configs.contains("constants"));
    assert(configs.contains("variables"));
    assert(configs.contains("per-audience"));
    assert(configs.contains("per-player"));
    assert(configs.contains("rules"));
}
// END-TODO

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