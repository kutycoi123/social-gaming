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

void GameSession::addUserIDToSession(int userID) { 
    _playersIDInSession.push_back(userID);
}
void GameSession::addUserToSession(Player player) { 
    _playersList.push_back(player);
}

size_t GameSession::totalPlayerCount(){
    return _playersInSession.size();
}

void GameSession::removeUserFromSession(int userID) { 
    _playersInSession.remove(userID);
}

void GameSession::removeAllUsersfromSession(){ 
    _playersInSession.clear();
}

int GameSession::sessionConfigureSettings(std::string jsonSettings) { 
    this->_JSONSetting = jsonSettings;
    Json settings = {
        "configuration": {
            "name": "Zen Game",
            "player count": {"min": 0, "max": 0},
            "audience": false,
            "setup": { }
        },
        "constants": {},
        "variables": {},
        "per-player": {},
        "per-audience": {},
        "rules": {}
        };
        this-> totalPlayers = settings["configuration"]["player count"]["max"];
        this->_ListSettingVars = settings["variables"];
        this->_ListPerAudience = settings["per-audience"];

}

void  GameSession::SetTotalNumPlayers(int totalPlayers) { 
    this->_totalNumPlayers = totalPlayers
}

void  GameSession::createInviteCode() { 
    Invitation codeGenerator;
    this->_invitationCode = codeGenerator.generateInvitationCode();
}

void  GameSession::setOwner(int ownerID) { 
    this->_ownerID = ownerID;
}

void  GameSession::getPlayers(int ownerID) { 
    return this->_playersList;
}

void GameSession::SetPlayerInviteCodes() {
    std::list<GameSession>::iterator it;

    for (it = _playersList.begin(); it != _playersList.end(); it++) {
        it->setInvitation(getInvitationCode);
    }
}