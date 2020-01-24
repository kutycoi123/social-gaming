#include <strings>

#include "include/Owner.h"
#include "Session.h"

// TODO: Incorporate JSON CPP library from https://github.com/nlohmann/json

// #include <nlohmann/json.hpp>
// using json = nlohmann::json

Owner::Owner() {
    list<Session> _listOfOwnedSessions;
}

list<Session> GetOwnedSessions() {
    return _listOfOwnedSessions;
}

void CreateSession(json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Number Of Players"] = 4;
    sessionSettings["GameId"] = 0;

    Session * newSession = new Session();

    for (auto& [key, value] : json.items()) {
        if (key.compare("Number Of Players")) {
            newSession->numberOfPlayers = value;
        }
        if (key.compare("Game")) {
            newSession->gameId = value;
        }
    }
}

void ConfigureSession(Session& session, json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Number Of Players"] = 4;
    sessionSettings["GameId"] = 0;

    for (auto& [key, value] : json.items()) {
        if (key.compare("Number Of Players")) {
            session->numberOfPlayers = value;
        }
        if (key.compare("Game")) {
            session->gameId = value;
        }
    }
}

void KickPlayer(Session& session, int playerId) {
    // TODO: Implement remove player method in Session class
    (session->*removePlayer)(playerId);
}

void ChangeOwner(Session& session, int newOwnerId) {
    session->ownerId = newOwnerId;
}