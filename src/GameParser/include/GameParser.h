 
#include <list>
#include <nlohmann/json.hpp>

#include <cassert>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
#ifndef GAME_PARSER_H
#define GAME_PARSER_H

enum StatusCode {
  VALID,
  INVALID
};
enum gameJsonFields {
  CONFIGURATION,
  RULES,
  CONSTANTS,
  VARIABLES,
  PERAUDIENCE,
  PERPLAYER
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
    void configValidator(const nlohmann::json& configs);
    StatusCode rulesValidation(const nlohmann::json& gameConfiguration);
    nlohmann::json fileToJson(const std::string& pathName);
    void parseEntireGameJson(const nlohmann::json& gameJson);
    const std::unordered_map<std::string, gameJsonFields> gameJsonMap{
        {
          {"configuration", gameJsonFields::CONFIGURATION},
          {"rules", gameJsonFields::RULES},
          {"constants", gameJsonFields::CONSTANTS},
          {"variables", gameJsonFields::VARIABLES},
          {"per-player", gameJsonFields::PERPLAYER},
          {"per-audience", gameJsonFields::PERAUDIENCE},
        }
        
    };

  private:
      void handleOtherFields(const std::string& nonRules);
      void processRuleField(const std::string& singleRule);
      void dealWithNestedRules(const nlohmann::json& rules);
      void parseRules(const nlohmann::json& rules);
      void parseConfiguration(const nlohmann::json& gameConfiguration);
      void setPerAudience(const nlohmann::json& perAudience);
      void setPerPlayer(const nlohmann::json& perPlayer);
      void setVariables(const nlohmann::json& variables);
      void setConstants(const nlohmann::json& constants);
      nlohmann::json constants;
      nlohmann::json variables;
      nlohmann::json perAudience;
      nlohmann::json gameConfiguration;
      std::string gameName;
      nlohmann::json rules;
      Config configSettings;
};
#endif
