#include <list>
#include <vector>
#include <string>
#include "../../sessions/include/GameSession.h"
using namespace std;

class Owner { 
    public:
        void createSession();
        void configureSession(GameSession& session);
        vector<GameSession> getSessionsOwned();
        void kickPlayer(GameSession& session, int playerId);
        void changeOwner(GameSession& session, int newOwnerId);
        int getNumberOfOwnedSessions();

    private:
        int _numberOfOwnedSessions;
        vector<GameSession> _ownedSessions;
}