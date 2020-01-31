#include "include/GameSession.h"

GameSession::GameSession(int ownerID) : 
    _invitationCode (Invitation()), 
    _ownerID (ownerID) {}

std::string GameSession::getInvitationCode() const {
    return _invitationCode.getInvitationCode();
}

void GameSession::setCurrentGame(std::string name) {
    this->_currentGame = name;
}

void GameSession::addUserToSession(int userID) { 
    _playersInSession.push_back(userID);
}

void GameSession::removeUserFromSession(int userID) { 
    _playersInSession.remove(userID);
}

void GameSession::removeAllUsersfromSession(){ 
    _playersInSession.clear();
}

int GameSession::sessionConfigureSettings(std::string jsonSettings) { 
    this->_JSONSetting = jsonSettings;
    return 123;
}




