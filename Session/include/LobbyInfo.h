#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
#include <unordered_map>
#include "SessionsInfo.h"


class LobbyInfo {
  
    public:

        int generatePlayerId(std::string gameName, std::string playerName);
        int addusersToSessions(int playerId, std::string game);
        bool sessionExists(int inviteCode);
        int createSession();
        int generateSessionID(SessionsInfo session);

    private:
    
        std::list<SessionsInfo> SessionsList;
        std::vector<int> inviteCodes;
        std::list<int> CurrentUsers; 
        std::unordered_map<int, std::string> UserIdToGame;
        std::unordered_map<int, std::string> SessionToInviteCode;       
};