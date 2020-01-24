
#include "Sessions.h"
// for 1 session the info for it to work. 
// infor on each session of a game, 

using namespace std; 

class Sessions { 
private:
    vector<int> UsersInSessions;
    string currentGame;
    int InvideCode;
    int sessionID;
    int gameID;
    int OwnerID;
    string JSONSetting;

public:

    void setOwner(int ownderid){
        this->OwnerID = ownderid;
    }
    void setCurrentGame(string name) {
        this->currentGame = name;
    }
    
    void addUserToSession( int Userid) {
        UsersInSessions.push_back(Userid);
    }
    void removeAllUserfromSession(){
        UsersInSessions.clear();
    }

    void sessionConfigureSettings(string jsonSettings) {
        this->JSONSetting = jsonSettings;
    }

};
    
