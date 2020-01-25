#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
#include <unordered_map>
#include "SessionsInfo.h"


class LobbyInfo {
  
    public:

        int GeneratePlayerId(std::string gameName, std::string playerName);
        int AddusersToSessions(int playerId, string game);
        bool SessionExists(int inviteCode);
        int createSession();
        int generateSessionID(SessionsInfo session);

    private:
    
        std::list<SessionsInfo> SessionsList;
        std::vector<int> inviteCodes;
        std::list<int> CurrentUsers; 
        std::unordered_map<int, string> UserIdToGame;
        std::unordered_map<int, string> SessionToInviteCode;       
};