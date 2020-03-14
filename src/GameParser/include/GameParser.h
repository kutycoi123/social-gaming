
#ifndef GAME_PARSER_H
#define GAME_PARSER_H
 
#include <list>
#include <nlohmann/json.hpp>

#include <cassert>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <map>
#include "AbstractSpec.h"
#include "BaseRule.h"
#include "Game.h"
#include "ForEach.h"
#include "Inparallel.h"
#include "Loop.h"
#include "Parallelfor.h"
#include "Reverse.h"

#include "GameSpecHelper.h"
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

    //The constructor should take in a string which is the filepath of the appropriate Game JSON, create the game, and store the game in a member variable
    GameParser(const std::string&);
    //This returns the Game object that was created by the Constructor
    //Unique ptr gets returned and reset so this object should be deleted after because it should be useless
    std::unique_ptr<Game> getGame() noexcept;


    


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
	
    const GameSpecification::GameSpec &getGameSpecifications() const;

  private:

        void configValidator(const nlohmann::json& configs);
        StatusCode validateRules(const nlohmann::json& incomingRules);
        nlohmann::json fileToJson(const std::string& pathName);
        void parseEntireGameJson(const nlohmann::json& gameJson);


        void validator(const nlohmann::json& gameConfiguration);



        StatusCode validGameJson(const nlohmann::json& );

        StatusCode validateConfiguration(const nlohmann::json&);
        StatusCode validatePlayerNumber(nlohmann::json&);
          void handleOtherFields(const std::string& nonRules);
          void processRuleField(const nlohmann::json& singleRule );

          void parseRules(const nlohmann::json& rules);
          void parseConfiguration(const nlohmann::json& gameConfiguration);
          void setPerAudience(const nlohmann::json& perAudience);
          void setPerPlayer(const nlohmann::json& perPlayer);
          void setVariables(const nlohmann::json& variables);
          void setConstants(const nlohmann::json& constants);

          nlohmann::json constants;
          nlohmann::json variables;
          nlohmann::json perAudience;
          nlohmann::json perPlayer;
          nlohmann::json gameConfiguration;
          std::string gameName;
          nlohmann::json rules;
          Config configSettings;
          const std::string CONFIGURATION_STRING = "configuration";
          const std::string PLAYER_COUNT = "player count";
          const std::string MIN = "min";
          const std::string MAX = "max";
          const std::string NUMBER = "number";

          GameSpecification::GameSpec gameSpecifications;

          std::unique_ptr<Game> game;
};
#endif
