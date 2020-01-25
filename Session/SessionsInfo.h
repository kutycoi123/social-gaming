#include <iostream> 
#include <string>
#include <vector>

// for 1 session the info for it to work. 
// infor on each session of a game, 
//

class SessionsInfo { 
    
public:

    void setOwner(int ownerID);
    void setCurrentGame(std::string name);
    void addUserToSession(int userID);
    void removeAllUserfromSession();
    void sessionConfigureSettings(std::string jsonSettings);

private:

    std::vector<int> usersInSessions;
    std::string currentGame;
    int invideCode;
    int sessionID;
    int gameID;
    int ownerID;
    std::string JSONSetting;

};