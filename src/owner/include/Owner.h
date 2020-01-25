#include <list>

using namespace std;

class Owner { 
    public:
        Session * createSession();
        void configureSession(Session& session);
        list<Session> getSessionsOwned();
        void kickPlayer(Session& session, int playerId);
        void changeOwner(Session& session, int newOwnerId);

    private:
        list<Sessions> _listOfOwnedSessions;
}