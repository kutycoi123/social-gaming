#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>

// for 1 session the info for it to work. 
// infor on each session of a game, 
//
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

    void setOwner(int ownderid);
    void setCurrentGame(string name);
    void addUserToSession( int Userid);
    void removeAllUserfromSession();
    void sessionConfigureSettings(string jsonSettings);

};