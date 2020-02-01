
#include "include/Owner.h"
#include "../sessions/include/GameSession.h"
#include "../player/include/Player.h"
// Incorporate JSON CPP library from https://github.com/nlohmann/json
#include <nlohmann/json.hpp>
using json = nlohmann::json

Owner::Owner() {
    list<Session> _listOfOwnedSessions;
}

list<Session> Owner::getOwnedSessions() {
    return _listOfOwnedSessions;
}

Session * Owner::createSession(json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Number Of Players"] = 4;
    sessionSettings["GameId"] = 0;

    _listOfOwnedSessions.

    for (auto& [key, value] : json.items()) {
        if (key.compare("Number Of Players")) {
            (newSession->setNumberOfPlayers(value));
        }
        if (key.compare("Game")) {
            (newSession->setGameId(value));
        }
    }

    return newSession;
}

void Owner::configureSession(int sessionIndex, json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Player count"] = 4;
    
    GameSession newGameSession;
    auto TotalPlayers = sessionSettings.find("Number Of Players");

    std::list<GameSession>::iterator it = _listOfOwnedSessions.begin();
 
    // Advance the iterator by 2 positions,
    std::advance(it, 2);

    newGameSession->setNumberOfPlayers(*TotalPlayers);

    }
}

void Owner::kickPlayer(GameSession& session, int playerId) {
    // TODO: Implement remove player method in Session class
    GameSession->removeUserFromSession(playerId);
}

void Owner::changeOwner(GameSession& session, int newOwnerId) {
    GameSession->setOwnerId(newOwnerId);
}

void Owner::SendInvideCode(int index, Player player) {

    _listOfOwnedSessions
}