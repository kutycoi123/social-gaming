
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
#include "BaseRule.h"

#include "GameSpec.h"

#include "Add.h"
#include "ForEach.h"
#include "Deal.h"
#include "Discard.h"
#include "Extend.h"
#include "ForEach.h"
#include "GlobalMessage.h"
#include "Inparallel.h"

#include "InputChoice.h"
#include "InputText.h"
#include "InputVote.h"
#include "Loop.h"
#include "Message.h"
#include "Parallelfor.h"
#include "Reverse.h"

#include "Shuffle.h"
#include "Sort.h"
#include "Timer.h"

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
    std::unordered_map<std::string,GameSpecification::RuleType> stringRuleMap = {
            {"foreach", GameSpecification::RuleType::ForEachType},
            {"loop", GameSpecification::RuleType::LoopType,},
            {"inparallel",GameSpecification::RuleType::InparallelType,},
            {"parallelfor",GameSpecification::RuleType::ParallelforType,},
            {"switch",GameSpecification::RuleType::SwitchType,},
            {"when",GameSpecification::RuleType::WhenType,},
            {"extend", GameSpecification::RuleType::ExtendType, },
            {"reverse",GameSpecification::RuleType::ReverseType, },
            {"shuffle",GameSpecification::RuleType::ShuffleType, },
            {"sort",GameSpecification::RuleType::SortType, },
            {"deal",GameSpecification::RuleType::DealType, },
            {"discard",GameSpecification::RuleType::DiscardType, },
            {"add",GameSpecification::RuleType::AddType, },
            {"timer",GameSpecification::RuleType::TimerType,},
            {"input-choice",GameSpecification::RuleType::InputChoiceType, },
            {"input-text",GameSpecification::RuleType::InputTextType, },
            {"message",GameSpecification::RuleType::MessageType, },
            {"global-message",GameSpecification::RuleType::GlobalMessageType, },
            {"scores",GameSpecification::RuleType::ScoresType, },
            {"unknown",GameSpecification::RuleType::Unknown, }
    };

    const GameSpecification::GameSpec &getGameSpecifications() const;

  private:
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

};
#endif
