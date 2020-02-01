
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

void Owner::createSession(json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Number Of Players"] = 4;

    auto TotalPlayers = sessionSettings.find("Number Of Players");
    GameSession newSession;
    newSession.setNumberOfPlayers(*TotalPlayers);
    _listOfOwnedSessions.push_back(newSession);
 
}

void Owner::configureSession(int sessionIndex, json sessionSettings) {
    // Mocking some JSON values
        sessionSettings["Player count"] = 4;
        
    GameSession newGameSession;
    auto TotalPlayers = sessionSettings.find("Number Of Players");


    std::list<GameSession>::iterator it = _listOfOwnedSessions.begin();
    std::advance(it, sessionIndex);
    it->setNumberOfPlayers(TotalPlayers);

}

void Owner::kickPlayer(GameSession& session, int playerId) {
    // TODO: Implement remove player method in Session class
    GameSession->removeUserFromSession(playerId);
}

void Owner::changeOwner(GameSession& session, int newOwnerId) {
    GameSession->setOwnerId(newOwnerId);
}

 