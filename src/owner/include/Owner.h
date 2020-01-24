#include <list>

using namespace std;

class Owner { 
public:
    void CreateSession();
    void ConfigureSession(Session& session);
    list<Session> GetSessionsOwned();
    void KickPlayer(Session& session, int playerId);
    void ChangeOwner(Session& session, int newOwnerId);

private:
    list<Sessions> _listOfOwnedSessions;
}