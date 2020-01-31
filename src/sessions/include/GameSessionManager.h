#ifndef GAME_SESSION_MANAGER_H
#define GAME_SESSION_MANAGER_H

#include "GameSession.h"
#include "../../invitation/include/Invitation.h"
#include <unordered_map>

class GameSessionManager {
public:
    static GameSession joinGameSession(int playerId, Invitation invitationCode);
    static GameSession createGameSession(int playerId);
    static bool sessionExists(Invitation invitation);
private:
    static std::vector<GameSession> _sessionsList;
    static std::vector<Invitation> _inviteCodes;
    static std::unordered_map<std::string, GameSession> _invitationToGameSessionMap; 
};

#endif