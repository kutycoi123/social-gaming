#include "include/GameSession.h"

GameSession::GameSession(User& owner) : 
    _invitationCode (Invitation()), 
    _owner (owner) {}

Invitation GameSession::getInvitationCode() const {
    return _invitationCode;
}

void GameSession::setCurrentGame(std::string name) {
    this->_currentGame = name;
}

void GameSession::addUserToSession(User& user) { 
    // TODO: UserList may need to be revised in order to accodomate this operation better.
    _usersInSession.addUser(user.getUserId());
}

size_t GameSession::totalPlayerCount() const noexcept {
    return _usersInSession.size();
}

void GameSession::removeUserFromSession(User& user) { 
    // TODO: UserList may need to be revised in order to accodomate this operation better.
    _usersInSession.removeUser(user.getUserId());
}

void GameSession::removeAllUsersfromSession(){ 
    _usersInSession.removeAllUsers();
}

int GameSession::sessionConfigureSettings(std::string jsonSettings) { 
    this->_JSONSetting = jsonSettings;

    //dummy value
    return 0;
}

UserList GameSession::getUsersInSession() {
    return _usersInSession;
}
