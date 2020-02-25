#ifndef GAMEGENERALCONFIG_H
#define GAMEGENERALCONFIG_H

#include <string>
#include <unordered_map>
#include "AbstractSpec.h"

namespace GameSpecification{
struct PlayerCount{
    int min;
    int max;  
};

using Setup = std::unordered_map<std::string, SpecValue>;


class GameGeneralConfig{
    public:
        GameGeneralConfig();
        GameGeneralConfig(const std::string& );

        std::string getName() const;
        PlayerCount getPlayerCount() const;
        bool hasAudience() const;
        Setup getSetup() const;

        void setName(const std::string& );
        void setPlayerCount(const PlayerCount& );
        void setAudience(bool );
        void setSetup(const Setup& );

    private:
        std::string name;
        PlayerCount playerCount;
        bool audience;
		Setup setup;

};
}
#endif
