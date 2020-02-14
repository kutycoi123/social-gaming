 
#include <list>
#include <nlohmann/json.hpp>
#include <cassert>
#include <fstream>
#include <string>
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

struct config {
  std::string name;
  int maxPlayercount;
  int minPlayercount;
  bool audience;
  nlohmann::json setup;

};
class GameEngine{
  public:
    GameEngine();
    void parseJSON(nlohmann::json gameConfiguration);
    void createGame();
    nlohmann::json stringTOJson(std::string);
    void validator(nlohmann::json gameConfiguration);
    void rulesValidation(nlohmann::json gameConfiguration);
    nlohmann::json fileToJson(std::string pathName);

    void readRules();

  private:
      nlohmann::json constants;
      nlohmann::json variables;
      nlohmann::json perAudience;
      nlohmann::json _gameConfiguration;
      std::string _GameName;
      nlohmann::json _rules;
      config configSettings;
};
#endif
