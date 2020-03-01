#include "GameSession.h"

GameSession::GameSession(User& owner) : 
    messages({}),
    invitationCode (Invitation::createNewInvitation()),
    gameSpec{},
    gameState{gameSpec},
    owner (owner)
{}

Invitation GameSession::getInvitationCode() const {
    return invitationCode;
}

bool GameSession::isOwner(const User& user) const {
    return (user == owner);
}

bool GameSession::isGameStarted() const {
    return gameState.isGameStarted();
}

void GameSession::startGame() {
    gameState.startGame();
}

void GameSession::addMessages(const std::string &message) noexcept{
    messages.push_back(message);
}

std::list<std::pair<UserId, std::string>> GameSession::getLobbyMessages() noexcept{
    std::list<std::pair<UserId, std::string>> result = {};

    for(auto& message : messages){
        
        auto playerListIterator = playerList.begin();

        while(playerListIterator != playerList.end()){
            result.push_back(std::make_pair(playerListIterator->first, message));
            playerListIterator++;
        }
    }
    

    return result;
}

void GameSession::clearMessages() noexcept {
    messages = {};
}

std::list<std::pair<UserId, std::string>> GameSession::updateAndGetAllMessages() noexcept{

    auto messages = getLobbyMessages();

    //TODO: if game started, do something else

    clearMessages();

    return messages;
}

void GameSession::addPlayer(const User& player) noexcept{
    playerList.add(player.getUserId());
}
void GameSession::removePlayer(const User& player) noexcept{
    playerList.remove(player.getUserId());
}