#include "include/SessionsInfo.h"
// for 1 session the info for it to work. 
// infor on each session of a game, 

void SessionsInfo::setOwner(int ownerID) {
    this->ownerID = ownerID;
}

void SessionsInfo::setCurrentGame(std::string name) {
    this->currentGame = name;
}

void SessionsInfo::addUserToSession( int userID) { 
    usersInSessions.push_back(userID);
}

void SessionsInfo::removeAllUserfromSession(){ 
    usersInSessions.clear();
}

int SessionsInfo::sessionConfigureSettings(std::string jsonSettings) { 
    this->JSONSetting = jsonSettings;
    return 123;
}




