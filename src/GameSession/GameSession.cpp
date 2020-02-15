#include "include/GameSession.h"
#include "GameSessionManager.h"
#include "Game.h"
#include <nlohmann/json.hpp>

GameSession::GameSession(User& owner) : 
    _invitationCode (Invitation::createNewInvitation()), 
    _owner (owner),
    _isGameStarted(false)
    // game(nlohmann::json gameSettings) 
{}

Invitation GameSession::getInvitationCode() const {
    return _invitationCode;
}

std::string GameSession::getSessionName() const {
    return _sessionName;
}

bool GameSession::doesUserOwnGame(const User& user) const {
    return (user == _owner);
}

bool GameSession::isGameStarted() const {
    return _isGameStarted;
}

void GameSession::setConfigurationSettings(std::string jsonSettings) { 
    _JSONSetting = jsonSettings;
}

void GameSession::startGame() {
    _isGameStarted = true;
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