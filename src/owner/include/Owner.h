#include <list>
#include <string>
#include "../sessions/include/GameSession.h"
using namespace std;

class Owner { 
    public:
        void createSession();
        void configureSession(GameSession& session);
        list<GameSession> getSessionsOwned();
        void kickPlayer(GameSession& session, int playerId);
        void changeOwner(GameSession& session, int newOwnerId);

    private:
        list<Sessions> _listOfOwnedSessions;
}