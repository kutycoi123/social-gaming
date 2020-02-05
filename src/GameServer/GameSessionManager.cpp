#include "GameSession.h"
#include "Invitation.h"
#include <unordered_map>
#include <optional>

namespace GameSessionManager{
    static std::list<GameSession> _sessionsList;
    static std::list<Invitation> _inviteCodes;
    static std::unordered_map<std::string, GameSession> _invitationToGameSessionMap; 

    GameSession createGameSession(const User&);
    std::optional<GameSession> joinGameSession(const User& player, const Invitation& invitation);
    void endGameSession(const GameSession& gameSession);
    size_t totalSessionCount();
    std::optional<Invitation> sessionExists(const Invitation& invitation);
    bool inSession(const User&);
    std::vector<networking::Message> constructGameSessionMessage(const User&, const std::string& message);

    GameSession createGameSession(const User& owner){
        GameSession gameSession{owner.getId()};
        _sessionsList.push_back(gameSession);
        _invitationToGameSessionMap.insert(std::make_pair(gameSession.getInvitationCode().toString(), gameSession));
        return gameSession;
    }

    std::optional<GameSession> joinGameSession(int playerId, const Invitation& invitation){
        auto found = _invitationToGameSessionMap.find(invitation.toString());
        if (found == _invitationToGameSessionMap.end()){
            return std::nullopt;
        }
        auto gameSession = found->second;
        gameSession.addUserToSession(playerId);
        return std::optional<GameSession>{gameSession};
    }

    void endGameSession(const GameSession& gameSession){
        auto invitationCode = gameSession.getInvitationCode();
        if (sessionExists(invitationCode)){
            _invitationToGameSessionMap.erase(invitationCode.toString());
            //_sessionsList.remove(gameSession);
        }
    }

    size_t totalSessionCount(){
        return _sessionsList.size();
    }

    std::optional<Invitation> sessionExists(const Invitation& invitation) {
        auto found = _invitationToGameSessionMap.find(invitation.toString());
        if (found == _invitationToGameSessionMap.end()){
            return std::nullopt;
        }
        return std::optional<Invitation>{invitation};
    }

    bool inSession(const User& user){

        //dummy code
        return false;
    }

    std::vector<networking::Message> constructGameSessionMessage(const User&, const std::string& message){

        //dummy code
        return {};
    }
}