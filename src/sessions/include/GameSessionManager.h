#ifndef GAME_SESSION_MANAGER_H
#define GAME_SESSION_MANAGER_H

#include "GameSession.h"
#include "../../invitation/include/Invitation.h"
#include <unordered_map>
#include <optional>

class GameSessionManager {
public:
    static std::optional<GameSession> joinGameSession(int playerId, const Invitation& invitation);
    static GameSession createGameSession(int ownerID);
    static void endGameSession(const GameSession& gameSession);
    static std::optional<Invitation> sessionExists(const Invitation& invitation);
    static size_t totalSessionCount();
private:
    static std::list<GameSession> _sessionsList;
    static std::list<Invitation> _inviteCodes;
    static std::unordered_map<std::string, GameSession> _invitationToGameSessionMap; 
};

#endif