#include "include/GameSession.h"
// for 1 session the info for it to work. 
// infor on each session of a game, 

GameSession::GameSession() : 
    _invitationCode (Invitation()) {}

std::string GameSession::getInvitationCode() const {
    return _invitationCode.getInvitationCode();
}

void GameSession::setOwner(int ownerID) {
    this->_ownerID = ownerID;
}

void GameSession::setCurrentGame(std::string name) {
    this->_currentGame = name;
}

void GameSession::addUserToSession( int userID) { 
    _playersInSession.push_back(userID);
}

void GameSession::removeAllUserfromSession(){ 
    _playersInSession.clear();
}

int GameSession::sessionConfigureSettings(std::string jsonSettings) { 
    this->_JSONSetting = jsonSettings;
    return 123;
}




