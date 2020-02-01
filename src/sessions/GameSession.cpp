#include "include/GameSession.h"

GameSession::GameSession(int ownerID) : 
    //_invitationCode (Invitation()), 
    _ownerID (ownerID) {}

Invitation GameSession::getInvitationCode() const {
    return _invitationCode;
}

void GameSession::setCurrentGame(std::string name) {
    this->_currentGame = name;
}

void GameSession::addUserToSession(int userID) { 
    _playersInSession.push_back(userID);
}

size_t GameSession::totalPlayerCount(){
    return _playersIDInSession.size();
}

void GameSession::removeUserFromSession(int userID) { 
    _playersIDInSession.remove(userID);
}

void GameSession::removeAllUsersfromSession(){ 
    _playersIDInSession.clear();
}

int GameSession::sessionConfigureSettings(std::string jsonSettings) { 
    this->_JSONSetting = jsonSettings;
<<<<<<< HEAD
    return 123;
}
=======

}

void  GameSession::SetTotalNumPlayers(int totalPlayers) { 
    this->_totalNumPlayers = totalPlayers;
}

void  GameSession::createInviteCode() { 
    Invitation codeGenerator;
    this->_invitationCode = "123";
}

void  GameSession::setOwner(int ownerID) { 
    this->_ownerID = ownerID;
}

std::list<Player> GameSession::getPlayers() { 
    return this->_playersList;
}

void GameSession::SetPlayerInviteCodes() {
    std::list<Player>::iterator it;
    
    for (it = _playersList.begin(); it != _playersList.end(); it++) {
        it->setInvitationCode(_invitationCode);
    }
}
>>>>>>> 934dd06a0ce8f58ef9b347462226443bea00c836
