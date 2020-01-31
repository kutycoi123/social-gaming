#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
#include <unordered_map>
#include "GameSession.h"


class LobbyInfo {
    public:
        int generatePlayerId(std::string gameName, std::string playerName);
    private:
        std::list<int> CurrentUsers; 
        std::unordered_map<int, std::string> UserIdToGame;      
};