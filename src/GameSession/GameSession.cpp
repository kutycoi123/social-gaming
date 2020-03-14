#include "GameSession.h"

GameSession::GameSession(std::weak_ptr<User>& owner, const std::string& gameFilePath) : 
    messages({}),
    invitationCode (Invitation::createNewInvitation()),
    owner (owner)
{
    auto parser = GameParser(gameFilePath);
    game = parser.getGame();
}

Invitation GameSession::getInvitationCode() const {
    return invitationCode;
}

//TODO: Check for owner, sessionList.IsOwner currently crashes program.
bool GameSession::isOwner(const UserId& user) const {
    return (user == owner.lock()->getUserId());
}

bool GameSession::isGameStarted() const {
    return game->isGameStarted();
}

void GameSession::startGame() {
    game->startGame(playerList.users);
}

void GameSession::endGame() {
    game->endGame();
}

void GameSession::addMessages(const std::string &message) noexcept{
    messages.push_back(message);
}

void GameSession::addMessagesToGame(const std::string &message) noexcept{
    if (isGameStarted()) {
        game->addMessages(message);
    }
}

std::list<std::pair<UserId, std::string>> GameSession::getLobbyMessages() noexcept{
    std::list<std::pair<UserId, std::string>> result = {};

    for(auto& message : messages){
        
       for(auto& player : playerList.users){
            result.emplace_back(player.lock()->getUserId(), message);
        }
    }    

    return result;
}

void GameSession::clearMessages() noexcept {
    messages = {};
}

std::list<std::pair<UserId, std::string>> GameSession::updateAndGetAllMessages() noexcept{

    auto messages = getLobbyMessages();
    if (game->isGameStarted()) {
        auto lobbyMessages = game->updateAndGetAllMessages();
        messages.insert(messages.end(), lobbyMessages.begin(), lobbyMessages.end());
    }

    clearMessages();

    return messages;
}

void GameSession::addPlayer(const std::weak_ptr<User>& player) noexcept{
    playerList.users.push_back(player);
}

void GameSession::removePlayer(const std::weak_ptr<User>& player) noexcept{
    
    auto playerIterator = std::find_if(playerList.users.begin(), playerList.users.end(), [player](std::weak_ptr<User> listMember){
        return player.lock()->getUserId() == listMember.lock()->getUserId();
    });
    
    if(playerIterator != playerList.users.end()){
        playerList.users.erase(playerIterator);
    }
}
