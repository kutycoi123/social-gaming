#include "include/GameSessionManager.h"


GameSession GameSessionManager::createGameSession(User& owner){
    GameSession gameSession{owner};
    _sessionsList.insert(gameSession);
    _invitationToGameSessionMap.insert(std::make_pair(gameSession.getInvitationCode(), gameSession));
    return gameSession;
}

std::optional<GameSession> GameSessionManager::joinGameSession(User& user, const Invitation& invitation){
    auto gameSession = findGameSession(invitation);

    // TODO: Investigate why isGameStarted() is still returning false
    bool canJoinSession = gameSession.has_value() && !(gameSession->isGameStarted());
    if (canJoinSession){
        gameSession.value().addUserToSession(user);
    }
    return gameSession;
}

// Finds corresponding game session to provided Invitation code
// Returns the GameSession if one is found or an empty optional if none is found 
std::optional<GameSession> GameSessionManager::findGameSession(const Invitation& invitation){
    auto found = _invitationToGameSessionMap.find(invitation);
    if (found == _invitationToGameSessionMap.end()){
        return std::nullopt;
    }
    auto gameSession = found->second;
    return std::optional<GameSession>{gameSession};
}

void GameSessionManager::startGameInGameSession(const Invitation& invitation){
    auto gameSession = findGameSession(invitation);
    if (gameSession){
        gameSession.value().startGame();
    }
}

void GameSessionManager::endGameSession(const Invitation& invitation){
    auto gameSession = findGameSession(invitation);
    if (gameSession){
        gameSession.value().removeAllUsersfromSession();
        _invitationToGameSessionMap.erase(invitation);
        _sessionsList.erase(gameSession.value());
    }
}

size_t GameSessionManager::totalSessionCount(){
    return _sessionsList.size();
}

std::deque<networking::Message> GameSessionManager::getAllGameMessages(){
    //Queries Game to get the replies from the game
    //dummy code
    return {};
}

std::deque<networking::Message> GameSessionManager::getAllLobbyMessages(){
    //queries lobbies to get replies from lobby
    //dummy code;
    return {};
}

    