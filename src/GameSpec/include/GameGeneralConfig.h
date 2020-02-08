#ifndef GAMEGENERALCONFIG_H
#define GAMEGENERALCONFIG_H

#include <string>

namespace GameSpecification{
struct PlayerCount{
    int min;
    int max;  
};

struct Setup{
    int round;
    //TODO: Add more fields when more details are provided
    
};

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
        std::string _name;
        PlayerCount _playerCount;
        bool _audience;
        Setup _setup;

};
}
#endif
