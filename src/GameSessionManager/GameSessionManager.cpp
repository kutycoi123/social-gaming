#include "include/GameSessionManager.h"

GameSession GameSessionManager::createGameSession(User& owner){
    GameSession gameSession{owner};
    _sessionsList.insert(gameSession);
    _inviteCodes.insert(gameSession.getInvitationCode());
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

std::optional<GameSession> GameSessionManager::findGameSession(const Invitation& invitation){
    auto found = _invitationToGameSessionMap.find(invitation);
    if (found == _invitationToGameSessionMap.end()){
        return std::nullopt;
    }
    auto gameSession = found->second;
    return std::optional<GameSession>{gameSession};
}

void GameSessionManager::endGameSession(GameSession& gameSession){
    auto invitationCode = gameSession.getInvitationCode();
    if (sessionExists(invitationCode)){
        gameSession.removeAllUsersfromSession();
        _invitationToGameSessionMap.erase(invitationCode);
        _inviteCodes.erase(invitationCode);
        _sessionsList.erase(gameSession);
    }
}


void GameSessionManager::MapUserIDToInvitation(const Invitation& invitation, uintptr_t id ){
    userToInviteCode.insert(std::make_pair(id,invitation));
}

size_t GameSessionManager::totalSessionCount(){
    return _sessionsList.size();
}

std::optional<Invitation> GameSessionManager::sessionExists(const std::string& invitationString){
    return sessionExists(Invitation::createInvitationFromStringInput(invitationString));
}

std::optional<Invitation> GameSessionManager::sessionExists(const Invitation& invitation) {
    auto found = _invitationToGameSessionMap.find(invitation);
    if (found == _invitationToGameSessionMap.end()){
        return std::nullopt;
    }
    return std::optional<Invitation>{found->first};
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

    