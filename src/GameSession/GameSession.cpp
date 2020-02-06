#include "include/GameSession.h"

GameSession::GameSession(int ownerID) : 
    _invitationCode (Invitation()), 
    _ownerID (ownerID) {}

Invitation GameSession::getInvitationCode() const {
    return _invitationCode;
}

void GameSession::setCurrentGame(std::string name) {
    this->_currentGame = name;
}

void GameSession::addUserToSession(uintptr_t userID) { 
    _playersIDInSession.push_back(userID);
}

size_t GameSession::totalPlayerCount() const noexcept{
    return _playersIDInSession.size();
}

void GameSession::removeUserFromSession(uintptr_t userID) { 
    _playersIDInSession.remove(userID);
}

void GameSession::removeAllUsersfromSession(){ 
    _playersIDInSession.clear();
}

int GameSession::sessionConfigureSettings(std::string jsonSettings) { 
    this->_JSONSetting = jsonSettings;

    //dummy value
    return 0;
}

void  GameSession::SetTotalNumPlayers(int totalPlayers) { 
    this->_totalNumPlayers = totalPlayers;
}

void  GameSession::setOwner(uintptr_t ownerID) { 
    this->_ownerID = ownerID;
}

// std::list<Player> GameSession::getPlayers() {   // TODO: Link with the User class
//     return this->_playersList;
// }

// void GameSession::SetPlayerInviteCodes() {  // TODO: Link with the User class
//     std::list<Player>::iterator it;
    
//     for (it = _playersList.begin(); it != _playersList.end(); it++) {
//         //it->setInvitationCode(_invitationCode);
//     }
// }
