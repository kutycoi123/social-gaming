#include<string>
#include<map>
#include <nlohmann/json.hpp>
using namespace std;

class JSONGAMEValidator
{
  public:
    enum GameSpecification{configuration,
                       constants,
                       variables,
                       perPlayer,
                       perAudience,
                       rules
    };
    enum GameConfiguration {name,
                      playerCount,
                      audience,
                      setup,
                      minPlayer,
                      maxPlayer,
                      rounds
    };

    map<std::string, GameSpecification> jsonGameSpecification = 
    {
      {"configuration", GameSpecification::configuration},
      {"constants", GameSpecification::constants},
      {"variables", GameSpecification::variables},
      {"per-player", GameSpecification::perPlayer},
      {"per-audience", GameSpecification::perAudience},
      {"rules", GameSpecification::rules}
    };

    map<std::string, GameConfiguration> jsonGameConfiguration = 
    {
      {"name", GameConfiguration::name},
      {"player count", GameConfiguration::playerCount},
      {"audience", GameConfiguration::audience},
      {"setup", GameConfiguration::setup},
      {"max", GameConfiguration::maxPlayer},
      {"min", GameConfiguration::minPlayer},
      {"Rounds", GameConfiguration::rounds}
    };
    void validGameJson(std::string& );
    void validateConfiguration(std::string&);

  private:
    std::string invalidUserInput;
};