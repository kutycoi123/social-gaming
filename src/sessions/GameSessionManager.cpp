#include "include/GameSession.h"
#include "include/GameSessionManager.h"

GameSession GameSessionManager::createGameSession(int ownerId){
    GameSession gameSession{ownerId};
    _sessionsList.push_back(gameSession);
    _invitationToGameSessionMap.insert(std::make_pair(gameSession.getInvitationCode().toString(), gameSession));
    return gameSession;
}

std::optional<GameSession> GameSessionManager::joinGameSession(int playerId, const Invitation& invitation){
    auto found = _invitationToGameSessionMap.find(invitation.toString());
    if (found == _invitationToGameSessionMap.end()){
        return std::nullopt;
    }
    auto gameSession = found->second;
    gameSession.addUserToSession(playerId);
    return std::optional<GameSession>{gameSession};
}

void GameSessionManager::endGameSession(const GameSession& gameSession){
    auto invitationCode = gameSession.getInvitationCode();
    if (sessionExists(invitationCode)){
        _invitationToGameSessionMap.erase(invitationCode.toString());
        _sessionsList.remove(gameSession);
    }
}

size_t GameSessionManager::totalSessionCount(){
    return _sessionsList.size();
}

std::optional<Invitation> GameSessionManager::sessionExists(const Invitation& invitation) {
    auto found = _invitationToGameSessionMap.find(invitation.toString());
    if (found == _invitationToGameSessionMap.end()){
        return std::nullopt;
    }
    return std::optional<Invitation>{invitation};
}