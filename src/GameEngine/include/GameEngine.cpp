#include "include/GameEngine.h"
 
//TODO: make into Enum table
//iterate if contains those then its good, 

//make into enum iterator-> 
//
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


//use enum things
//hashmap-> 
//loop hashmap for each things->  make this a loop might be ok..
// enum map of the word maybe-> 

//contains-> map-> enum key-> to word
//do this for all file types?
//enum to map. loop an enum list-> 
//for each rule. 

//intergrate with other classes call other classes to store things. 
bool GameEngine::validator(nlohmann::json gameConfiguration){
    assert(gameConfiguration.contains("gameConfiguration"));
    assert(gameConfiguration.contains("constants"));
    assert(gameConfiguration.contains("variables"));
    assert(gameConfiguration.contains("per-audience"));
    assert(gameConfiguration.contains("rules"));
    return true;
}

// use emum game field validator. 
//enum tables-> 
//cal validate bofre passing to each class-> 


nlohmann::json fileToJson(std::string pathName) {
  std::ifstream i("pathName");
  nlohmann::json JsonConfig;
  i >> JsonConfig;
  return JsonConfig;
}


