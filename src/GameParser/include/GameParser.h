 
#include <list>
#include <nlohmann/json.hpp>

#include <cassert>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
#include<map>
#ifndef GAME_PARSER_H
#define GAME_PARSER_H

enum GameSpecificationJSON{
    CONFIGURATION,
    CONSTANTS,
    VARIABLES,
    PER_PLAYER,
    PER_AUDIENCE,
    RULES
};
 
enum GameConfiguration {NAME,
    PLAYER_COUNT,
    AUDIENCE,
    SETUP,
    MIN_PLAYER,
    MAX_PLAYER
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
    enum StatusCode {
        VALID,
        INVALID
    };
    GameParser();
    void createGame();
    void parseJSON(const nlohmann::json& gameConfiguration);
    void configValidator(const nlohmann::json& configs);
    StatusCode rulesValidation(const nlohmann::json& incomingRules);
    nlohmann::json fileToJson(const std::string& pathName);
    void parseEntireGameJson(const nlohmann::json& gameJson);
   
    
    void validator(const nlohmann::json& gameConfiguration);

  
  
    StatusCode validGameJson(std::string& );
    
    StatusCode validateConfiguration(const nlohmann::json&);
    StatusCode validatePlayerNumber(nlohmann::json&);

    std::map<std::string, GameSpecificationJSON> jsonGameSpecification =
            {
                    {"configuration", GameSpecificationJSON::CONFIGURATION},
                    {"constants", GameSpecificationJSON::CONSTANTS},
                    {"variables", GameSpecificationJSON::VARIABLES},
                    {"per-player", GameSpecificationJSON::PER_PLAYER},
                    {"per-audience", GameSpecificationJSON::PER_AUDIENCE},
                    {"rules", GameSpecificationJSON::RULES}
            };

    std::map<std::string, GameConfiguration> jsonGameConfiguration =
            {
                    {"name", GameConfiguration::NAME},
                    {"player count", GameConfiguration::PLAYER_COUNT},
                    {"audience", GameConfiguration::AUDIENCE},
                    {"setup", GameConfiguration::SETUP},
                    {"max", GameConfiguration::MAX_PLAYER},
                    {"min", GameConfiguration::MIN_PLAYER}
            };


  private:
      void handleOtherFields(const std::string& nonRules);
      void processRuleField(nlohmann::json::iterator singleRule);
       
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
      std::string CONFIGURATIONString = "configuration";
      std::string PLAYER_COUNT = "player count";
      std::string MIN = "min";
      std::string MAX = "max";
      std::string NUMBER = "number";
};
#endif
