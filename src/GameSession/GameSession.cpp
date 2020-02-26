#include "include/GameSession.h"
#include "GameSessionManager.h"
#include "Game.h"
#include <nlohmann/json.hpp>

GameSession::GameSession(User& owner) : 
    invitationCode (Invitation::createNewInvitation()),
    owner (owner),
    gameStarted(false)
    // game(nlohmann::json gameSettings) 
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
    return gameStarted;
}

void GameSession::setConfigurationSettings(std::string jsonSettings) { 
    JSONSetting = jsonSettings;
}

void GameSession::startGame() {
    gameStarted = true;
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