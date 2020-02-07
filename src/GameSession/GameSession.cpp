#include "include/GameSession.h"

GameSession::GameSession(int ownerID) : 
    _invitationCode (Invitation()), 
    _ownerID (ownerID),
    _isGameStarted(false) {}

Invitation GameSession::getInvitationCode() const {
    return _invitationCode;
}

size_t GameSession::getTotalPlayerCount() const noexcept{
    return _playersIDInSession.size();
}

std::string GameSession::getSessionName() const {
    return _sessionName;
}

bool GameSession::isGameStarted() const {
    return _isGameStarted;
}

void GameSession::setCurrentGame(std::string name) {
    _currentGame = name;
}

void GameSession::setOwner(uintptr_t ownerID) { 
    _ownerID = ownerID;
}

void GameSession::setTotalNumPlayers(int totalPlayers) { 
    _totalNumPlayers = totalPlayers;
}

void GameSession::addUserToSession(uintptr_t userID) { 
    _playersIDInSession.push_back(userID);
}

void GameSession::removeUserFromSession(uintptr_t userID) { 
    _playersIDInSession.remove(userID);
}

void GameSession::removeAllUsersfromSession(){ 
    _playersIDInSession.clear();
}

void GameSession::setConfigurationSettings(std::string jsonSettings) { 
    _JSONSetting = jsonSettings;
}

void GameSession::startGame() {
    _isGameStarted = true;
}

void GameSession::setOwner(uintptr_t ownerID) { 
    this->_ownerID = ownerID;
}

// std::list<Player> GameSession::getPlayers() {   // TODO: Link with the User class
//     return this->_playersList;
// }

// void GameSession::setPlayerInviteCodes() {  // TODO: Link with the User class
//     std::list<Player>::iterator it;
    
//     for (it = _playersList.begin(); it != _playersList.end(); it++) {
//         //it->setInvitationCode(_invitationCode);
//     }
// }
