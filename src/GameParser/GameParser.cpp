#include <iostream>
#include "include/GameParser.h"
#include "BaseRule.h"

GameParser::GameParser() {};

void GameParser::parseJSON(nlohmann::json gameConfiguration) {
  // TODO: Refactor based on Hunars changes for validating game configurations
  if(gameConfiguration.find("gameConfiguration") != gameConfiguration.end()) {
    nlohmann::json configs = gameConfiguration["gameConfiguration"];

    this->configSettings.name = configs["name"];
    this->configSettings.audience = configs["audience"];
    this->configSettings.maxPlayercount = configs["player count"]["max"];
    this->configSettings.minPlayercount = configs["player count"]["in"];
    this->configSettings.setup = configs["setup"];
  }
  this->constants = gameConfiguration["constants"];
  this-> variables = gameConfiguration["variables"];
  this-> perAudience = gameConfiguration["per-audience"];
  // END-TODO

  if (GameParser::rulesValidation(gameConfiguration["rules"]) == StatusCode::VALID) {
    this->_rules = gameConfiguration["rules"];
  }
}

// TODO: Refactor based on Hunars changes for validating game configurations
void GameParser::validator(nlohmann::json gameConfiguration){
    assert(gameConfiguration.contains("gameConfiguration"));
    assert(gameConfiguration.contains("constants"));
    assert(gameConfiguration.contains("variables"));
    assert(gameConfiguration.contains("per-audience"));
    assert(gameConfiguration.contains("rules"));
}
// END-TODO

StatusCode GameParser::rulesValidation(nlohmann::json incomingRules) {
  auto ruleMap = GameSpecification::BaseRule::rulemap;

  for (nlohmann::json::iterator it = incomingRules.begin(); it != incomingRules.end(); ++it) {
    if (ruleMap.find(it.key()) == ruleMap.end()) {
      return StatusCode::INVALID;
    }
  }

  return StatusCode::VALID;
}

nlohmann::json fileToJson(std::string pathName) {
  std::ifstream i("pathName");
  nlohmann::json JsonConfig;
  i >> JsonConfig;
  return JsonConfig;
}