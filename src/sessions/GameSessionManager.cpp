#include "include/GameSessionManager.h"
#include "include/GameSession.h"

GameSession GameSessionManager::createGameSession(int ownerId){
    GameSession gameSession{ownerId};
    _sessionsList.push_back(gameSession);
    _invitationToGameSessionMap.insert(std::make_pair(gameSession.getInvitationCode(), gameSession));
    return gameSession;
}

GameSession GameSessionManager::joinGameSession(int playerId, const Invitation& invitation){
    auto gameSession = _invitationToGameSessionMap.at(invitation.getInvitationCode());
    gameSession.addUserToSession(playerId);
    return gameSession;
}

bool GameSessionManager::sessionExists(const Invitation& invitation){
    auto found = _invitationToGameSessionMap.find(invitation.getInvitationCode());
    return found != _invitationToGameSessionMap.end();
}