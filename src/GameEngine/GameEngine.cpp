#include <iostream>
#include "include/GameEngine.h"
#include "BaseRule.h"

GameEngine::GameEngine() {};

void GameEngine::parseJSON(nlohmann::json gameConfiguration) {
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
    this->_rules = gameConfiguration["rules"];
    //set name rules ect.. 
}

void GameEngine::validator(nlohmann::json gameConfiguration){
    assert(gameConfiguration.contains("gameConfiguration"));
    assert(gameConfiguration.contains("constants"));
    assert(gameConfiguration.contains("variables"));
    assert(gameConfiguration.contains("per-audience"));
    assert(gameConfiguration.contains("rules"));
}

void GameEngine::rulesValidation(nlohmann::json rules) {
  // TODO: Remove temporary stub of json rules
  nlohmann::json tempJsonStub;
  tempJsonStub["foreach"] = "Rule 1"; 
  tempJsonStub["test"] = "Rule 2";
  tempJsonStub["loop"] = "Rule 3";

  auto mapRules = GameSpecification::BaseRule::rulemap;

  for (nlohmann::json::iterator it = tempJsonStub.begin(); it != tempJsonStub.end(); ++it) {
    if (mapRules.find(it.key()) == mapRules.end()) {
      throw std::invalid_argument("Invalid rule specified");
    }
  }
}

nlohmann::json fileToJson(std::string pathName) {
  std::ifstream i("pathName");
  nlohmann::json JsonConfig;
  i >> JsonConfig;
  return JsonConfig;
}