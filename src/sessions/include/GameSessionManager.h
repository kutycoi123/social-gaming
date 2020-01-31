#ifndef GAME_SESSION_MANAGER_H
#define GAME_SESSION_MANAGER_H

#include "GameSession.h"
#include "../../invitation/include/Invitation.h"
#include <unordered_map>

class GameSessionManager {
public:
    static GameSession joinGameSession(int playerId, const Invitation& invitation);
    static GameSession createGameSession(int ownerID);
    static bool sessionExists(const Invitation& invitation);
private:
    static std::list<GameSession> _sessionsList;
    static std::list<Invitation> _inviteCodes;
    static std::unordered_map<std::string, GameSession> _invitationToGameSessionMap; 
};

#endif