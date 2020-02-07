#include "GameSession.h"
#include "Invitation.h"
#include <unordered_map>
#include <optional>
#include <system_error>

namespace GameSessionManager{
    //temporary struct to "pretend" as the game
    struct Game{
        std::string game;
    };

    static std::list<GameSession> lobbyList;
    static std::list<Game> gameList;
    static std::list<Invitation> _inviteCodes;
    static std::unordered_map<std::string, GameSession> _invitationToGameSessionMap; 

    size_t totalSessionCount(){
        return lobbyList.size();
    }

    std::optional<Invitation> sessionExists(const Invitation& invitation) {
        auto found = _invitationToGameSessionMap.find(invitation.toString());
        if (found == _invitationToGameSessionMap.end()){
            return std::nullopt;
        }
        return std::optional<Invitation>{invitation};
    }

    GameSession createGameSession(const User& owner){
        GameSession gameSession{owner.getId()};
        lobbyList.push_back(gameSession);
        _invitationToGameSessionMap.insert(std::make_pair(gameSession.getInvitationCode().toString(), gameSession));
        return gameSession;
    }

    //change booleon to error code
    void joinGameSession(const User& player, const std::string& invitation){
        auto found = _invitationToGameSessionMap.find(invitation);
        if (found == _invitationToGameSessionMap.end()){
            throw std::runtime_error("No such lobby");            
        }

        auto gameSession = found->second;
        gameSession.addUserToSession(player.getId());
    }

    void endGameSession(const GameSession& gameSession){
        auto invitationCode = gameSession.getInvitationCode();
        if (sessionExists(invitationCode)){
            _invitationToGameSessionMap.erase(invitationCode.toString());
            //lobbyList.remove(gameSession);
        }
    }

    std::deque<networking::Message> getAllGameMessages(){
        //Queries Game to get the replies from the game
        //dummy code
        return {};
    }

    std::deque<networking::Message> getAllLobbyMessages(){
        //queries lobbies to get replies from lobby
        //dummy code;
        return {};
    }
}