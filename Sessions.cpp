
#include "Sessions.h"
// for 1 session the info for it to work. 
// infor on each session of a game, 

using namespace std; 

class SessionsInfo { 
private:
    vector<int> UsersInSessions;
    string currentGameName;
    int InvideCode;
    int sessionID;
    int gameID;
    int OwnerID;
    int numberOfPlayers;
    string JSONSetting;
    
public:

    void setOwner(int ownerid){this->OwnerID = ownerid;}
    void setCurrentGame(string name) { this->currentGameName = name; }
    void addUserToSession( int Userid) { UsersInSessions.push_back(Userid);}
    void removeAllUserfromSession(){ UsersInSessions.clear();}
    int sessionConfigureSettings(string jsonSettings) { 
        this->JSONSetting = jsonSettings;
        return 123;
    }
};
    



