#include "GameSession.h"
#include "Invitation.h"
#include <unordered_map>
#include <optional>

namespace GameSessionManager{
    static std::list<GameSession> _sessionsList;
    static std::list<Invitation> _inviteCodes;
    static std::unordered_map<std::string, GameSession> _invitationToGameSessionMap; 

    GameSession createGameSession(const User&);
    bool joinGameSession(const User& player, const std::string& invitation);
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

    bool joinGameSession(const User& player, const std::string& invitation){
        auto found = _invitationToGameSessionMap.find(invitation);
        if (found == _invitationToGameSessionMap.end()){
            return false;
        }

        auto gameSession = found->second;
        gameSession.addUserToSession(player.getId());
        return true;
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
        //Check if given user is in a game session
        for(auto& session : _sessionsList){
            //if session contains player return true
        }
        //dummy code
        return false;
    }

    std::vector<networking::Message> constructGameSessionMessage(const User&, const std::string& message){
        //Queries GameSession to get the results of the game
        //dummy code
        return {};
    }
}