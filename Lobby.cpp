#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
#include "Sessions.h"

#include <unordered_map>

class LobbyInfo {
    private:
        list<Sessions> SessionsList;
        vector<int> inviteCodes;
        list<int> CurrentUsers; 
        unordered_map<int, string> UserIdToGame;
        unordered_map<int, string> SessionToInviteCode;
         
    public:
        int GeneratePlayerId(string gameName, string playerName) {
            int id = rand() % 10000; 
            return id;     
        }

        int AddusersToSessions(int playerId, string game) {
            UserIdToGame.insert(std::make_pair(playerId,game));
        }

        bool SessionExists(int inviteCode) {
            if ( SessionToInviteCode.find(inviteCode) == SessionToInviteCode.end()) { 
                return true; 
            }
        }
        int createSession() {
            Sessions newSession;
            SessionsList.push_back(newSession);
            int sessionId = generateSessionID(newSession);
            return sessionId;
        }
        int generateSessionID(Sessions session) {
            return 123;
        }


};