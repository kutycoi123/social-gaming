 
#include <list>
#include <nlohmann/json.hpp>
#include <cassert>
#include <fstream>
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

enum rule { forEach, inParallel,loop,inparallel,parallelFor,switchR }; 
  
class GameEngine{
  public:
    void parseJSON(nlohmann::json gameConfiguration);
    void createGame();
    nlohmann::json stringTOJson(std::string);
    void validator(nlohmann::json gameConfiguration);
    nlohmann::json fileToJson(std::string pathName);

    void readRules();

  private:
      nlohmann::json constants;
      nlohmann::json variables;
      nlohmann::json perAudience;
      nlohmann::json _gameConfiguration;
      std::string _GameName;
      nlohmann::json _rules;
      
};
#endif
