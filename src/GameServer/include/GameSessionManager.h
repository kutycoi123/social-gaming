#include "GameSession.h"
#include "Invitation.h"
#include <unordered_map>
#include <unordered_set>
#include <optional>

namespace GameSessionManager{
    namespace {
        struct InvitationHash {
            std::size_t operator()(const Invitation& invitation) const {
                return std::hash<std::string>()(invitation.toString());
            }
        };

        struct GameSessionHash {
            std::size_t operator()(const GameSession& gameSession) const {
                return std::hash<std::string>()(gameSession.getInvitationCode().toString());
            }
        };

        static std::unordered_set<GameSession, GameSessionHash> _sessionsList;
        static std::unordered_set<Invitation, InvitationHash> _inviteCodes;
        static std::unordered_map<Invitation, GameSession, InvitationHash> _invitationToGameSessionMap; 
    }

    GameSession createGameSession(int ownerId);
    std::optional<GameSession> joinGameSession(int playerId, const Invitation& invitation);
    void endGameSession(const GameSession& gameSession);
    size_t totalSessionCount();
    std::optional<Invitation> sessionExists(const std::string& invitationString);
    std::optional<Invitation> sessionExists(const Invitation& invitation);
}