 
#include <list>
#include <nlohmann/json.hpp>
#include <cassert>
#include <fstream>
#include <string>
#ifndef GAME_PARSER_H
#define GAME_PARSER_H

enum StatusCode {
  VALID,
  INVALID
};

struct Config {
  std::string name;
  int maxPlayercount;
  int minPlayercount;
  bool audience;
  nlohmann::json setup;
};

class GameParser{
  public:
    GameParser();
    void createGame();
    void parseJSON(const nlohmann::json& gameConfiguration);
    void validator(const nlohmann::json& gameConfiguration);
    StatusCode rulesValidation(const nlohmann::json& gameConfiguration);
    nlohmann::json fileToJson(const std::string& pathName);

  private:
      nlohmann::json constants;
      nlohmann::json variables;
      nlohmann::json perAudience;
      nlohmann::json gameConfiguration;
      std::string gameName;
      nlohmann::json rules;
      Config configSettings;
};
#endif
