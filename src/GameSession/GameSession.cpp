#include "include/GameSession.h"
#include "GameSessionManager.h"
#include "Game.h"
#include <nlohmann/json.hpp>

GameSession::GameSession(uintptr_t ownerID) : 
    _invitationCode (Invitation()), 
    _ownerID (ownerID),
    _isGameStarted(false)
    // game(nlohmann::json gameSettings)
    {}

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

// std::list<Player> GameSession::getPlayers() {   // TODO: Link with the User class
//     return this->_playersList;
// }

// void GameSession::setPlayerInviteCodes() {  // TODO: Link with the User class
//     std::list<Player>::iterator it;
    
//     for (it = _playersList.begin(); it != _playersList.end(); it++) {
//         //it->setInvitationCode(_invitationCode);
//     }
// }
