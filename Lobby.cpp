#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
#include "Sessions.h"

class Lobby {
    private:
        list<Sessions> SessionsList;
        list<int> inviteCodes;
        
    public:
        bool SessionExists(int inviteCode) {
            bool found = (std::find(inviteCodes.begin(), inviteCodes.end(), inviteCode) != inviteCodes.end());
            return found;
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