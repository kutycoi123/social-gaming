#include "GameSession.h"
#include "GameSessionManager.h"

GameSession::GameSession(User& owner) : 
    invitationCode (Invitation::createNewInvitation()),
    gameSpec{},
    gameState{gameSpec},
    owner (owner)
{}

Invitation GameSession::getInvitationCode() const {
    return invitationCode;
}

std::string GameSession::getSessionName() const {
    return sessionName;
}

bool GameSession::doesUserOwnGame(const User& user) const {
    return (user == owner);
}

bool GameSession::isGameStarted() const {
    return gameState.isGameStarted();
}

void GameSession::setConfigurationSettings(std::string& jsonSettings) {
    JSONSetting = jsonSettings;
}

void GameSession::startGame() {
    gameState.startGame();
}

void GameSession::addMessages(const std::string &message) {
    messages.push(message);
}

std::queue<std::string> GameSession::getMessages() {
     return messages;
 }

 void GameSession::clearMessages() {
    while(!messages.empty()) {
        messages.pop();
    }
 }