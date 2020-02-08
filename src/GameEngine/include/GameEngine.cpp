#include "include/GameEngine.h"
 

void GameEngine::parseJSON(nlohmann::json gameConfiguration) {
    if(gameConfiguration.find("gameConfiguration") != gameConfiguration.end()) {
      nlohmann::json configs = gameConfiguration["gameConfiguration"];
      std::string name = configs["name"];
      bool audience = configs["audience"];
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

nlohmann::json fileToJson(std::string pathName) {
  std::ifstream i("pathName");
  nlohmann::json JsonConfig;
  i >> JsonConfig;
  return JsonConfig;
}



