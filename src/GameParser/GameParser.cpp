#include <iostream>
#include "include/GameParser.h"
#include "BaseRule.h"

GameParser::GameParser() {};

void GameParser::parseJSON(const nlohmann::json& gameConfiguration) {
  // TODO: Refactor based on Hunars changes for validating game configurations
  if(gameConfiguration.find("gameConfiguration") != gameConfiguration.end()) {
    nlohmann::json configs = gameConfiguration["gameConfiguration"];

    _configSettings.name = configs["name"];
    _configSettings.audience = configs["audience"];
    _configSettings.maxPlayercount = configs["player count"]["max"];
    _configSettings.minPlayercount = configs["player count"]["in"];
    _configSettings.setup = configs["setup"];
  }
  _constants = gameConfiguration["constants"];
  _variables = gameConfiguration["variables"];
  _perAudience = gameConfiguration["per-audience"];
  // END-TODO

  if (GameParser::rulesValidation(gameConfiguration["rules"]) == StatusCode::VALID) {
    _rules = gameConfiguration["rules"];
  }
}

// TODO: Refactor based on Hunars changes for validating game configurations
void GameParser::validator(const nlohmann::json& gameConfiguration){
    assert(gameConfiguration.contains("gameConfiguration"));
    assert(gameConfiguration.contains("constants"));
    assert(gameConfiguration.contains("variables"));
    assert(gameConfiguration.contains("per-audience"));
    assert(gameConfiguration.contains("rules"));
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

nlohmann::json fileToJson(const std::string& pathName) {
  std::ifstream i(pathName);
  nlohmann::json JsonConfig;
  i >> JsonConfig;
  return JsonConfig;
}