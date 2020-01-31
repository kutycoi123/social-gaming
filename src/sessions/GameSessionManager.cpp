#include "include/GameSession.h"
#include "include/GameSessionManager.h"

GameSession GameSessionManager::createGameSession(int ownerId){
    GameSession gameSession{ownerId};
    _sessionsList.push_back(gameSession);
    _invitationToGameSessionMap.insert(std::make_pair(gameSession.getInvitationCode(), gameSession));
    return gameSession;
}

std::optional<GameSession> GameSessionManager::joinGameSession(int playerId, const Invitation& invitation){
    auto found = _invitationToGameSessionMap.find(invitation.getInvitationCode());
    if (found == _invitationToGameSessionMap.end()){
        return std::nullopt;
    }
    auto gameSession = found->second;
    gameSession.addUserToSession(playerId);
    return std::optional<GameSession>{gameSession};
}

size_t GameSessionManager::totalSessionCount(){
    return _sessionsList.size();
}

std::optional<Invitation> GameSessionManager::sessionExists(const Invitation& invitation) {
    auto found = _invitationToGameSessionMap.find(invitation.getInvitationCode());
    if (found == _invitationToGameSessionMap.end()){
        return std::nullopt;
    }
    return std::optional<Invitation>{invitation};
}