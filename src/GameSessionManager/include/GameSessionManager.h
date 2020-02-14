#include "GameSession.h"
#include "Invitation.h"
#include "User.h"
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <Server.h> //for networking::Message

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

        //dummy game type
        struct Game{
            std::string game;
        };

        static std::vector<Game> gameList {};
        
        static std::unordered_set<GameSession, GameSessionHash> _sessionsList;
        static std::unordered_set<Invitation, InvitationHash> _inviteCodes;
        static std::unordered_map<uintptr_t, Invitation> userToInviteCode; 
        static std::unordered_map<Invitation, GameSession, InvitationHash> _invitationToGameSessionMap;
    }

    GameSession createGameSession(User& owner);

    void MapUserIDToInvitation(const Invitation invitation,uintptr_t id);

    std::optional<GameSession> findGameSession(const Invitation& invitation);
    std::optional<GameSession> joinGameSession(User& user, const Invitation& invitation);
    void endGameSession(GameSession& gameSession);
    size_t totalSessionCount();
    std::optional<Invitation> sessionExists(const std::string& invitationString);
    std::optional<Invitation> sessionExists(const Invitation& invitation);
    std::deque<networking::Message> getAllGameMessages();
    std::deque<networking::Message> getAllLobbyMessages();

}