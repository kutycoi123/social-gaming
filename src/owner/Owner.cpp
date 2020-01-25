#include <strings>

#include "include/Owner.h"
#include "Session.h"

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

    Session * newSession = new Session();

    for (auto& [key, value] : json.items()) {
        if (key.compare("Number Of Players")) {
            (newSession->*setNumberOfPlayers(value));
        }
        if (key.compare("Game")) {
            (newSession->*setGameId(value));
        }
    }

    return newSession;
}

void Owner::configureSession(Session& session, json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Number Of Players"] = 4;
    sessionSettings["GameId"] = 0;

    for (auto& [key, value] : json.items()) {
        if (key.compare("Number Of Players")) {
            (session->*setNumberOfPlayers(value));
        }
        if (key.compare("Game")) {
            (session->*setGameId(value));
        }
    }
}

void Owner::kickPlayer(Session& session, int playerId) {
    // TODO: Implement remove player method in Session class
    (session->*removePlayer(playerId));
}

void Owner::changeOwner(Session& session, int newOwnerId) {
    (session->*setOwnerId(newOwnerId));
}