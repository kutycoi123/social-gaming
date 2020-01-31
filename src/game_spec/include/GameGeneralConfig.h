#ifndef GAMEGENERALCONFIG_H
#define GAMEGENERALCONFIG_H


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

        void setName(const std::string& name);
        void setPlayerCount(const PlayerCount& cnt);
        void setAudience(bool audience);
        void setSetup(const Setup& setup);

    private:
        std::string _name;
        PlayerCount _playerCnt;
        bool _audience;
        Setup _setup;

};

#endif
