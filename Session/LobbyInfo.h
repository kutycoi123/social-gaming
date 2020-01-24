#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
#include <unordered_map>
#include "SessionsInfo.h"


class LobbyInfo {
  
    public:

        int GeneratePlayerId(string gameName, string playerName);
        int AddusersToSessions(int playerId, string game);
        bool SessionExists(int inviteCode);
        int createSession();
        int generateSessionID(SessionsInfo session);

    private:
    
        list<SessionsInfo> SessionsList;
        vector<int> inviteCodes;
        list<int> CurrentUsers; 
        unordered_map<int, string> UserIdToGame;
        unordered_map<int, string> SessionToInviteCode;       
};