#include "SessionsInfo.h"
// for 1 session the info for it to work. 
// infor on each session of a game, 

void SessionsInfo::setOwner(int ownerID) {
    this->ownerID = ownerid;
}

void SessionsInfo::setCurrentGame(string name) {
    this->currentGameName = name;
}

void SessionsInfo::addUserToSession( int userID) { 
    UsersInSessions.push_back(Userid);
}

void SessionsInfo::removeAllUserfromSession(){ 
    UsersInSessions.clear();
}

int SessionsInfo::sessionConfigureSettings(string jsonSettings) { 
    this->JSONSetting = jsonSettings;
    return 123;
}




