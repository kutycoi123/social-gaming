#include "include/Owner.h"
#include "../sessions/include/GameSession.h"
#include "../player/include/Player.h"
// Incorporate JSON CPP library from https://github.com/nlohmann/json
#include <nlohmann/json.hpp>
using json = nlohmann::json

Owner::Owner() {
    _numberOfOwnedSessions = 0;
    std::vector<GameSession> _ownedSessions;
}

list<Session> Owner::getOwnedSessions() {
    return _ownedSessions;
}

int Owner::getNumberOfOwnedSessions() {
    return _numberOfOwnedSessions;
}

void Owner::createSession(json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Game"] = 6000;
    sessionSettings["Number Of Players"] = 4;
    sessionSettings["Game Length"] = 6000;

    // Create game session and configure
    GameSession gameSession = GameSession::GameSession(this->_id);
    gameSession.sessionConfigureSettings(sessionSettings);

    _numberOfOwnedSessions++;
    _ownedSessions.push_back(newSession);
}

void Owner::configureSession(int sessionId, json sessionSettings) {
    // Mocking some JSON values
    sessionSettings["Game"] = 6000;
    sessionSettings["Number Of Players"] = 4;
    sessionSettings["Game Length"] = 6000;

    // https://thispointer.com/using-stdfind-stdfind_if-with-user-defined-classes/
    std::vector<GameSession> gameSessions = getOwnedSessions();
    std::vector<GameSession>::iterator it;
    it = std::find_if(gameSessions.begin(), gameSessions.end() [](GameSession const& session) {
        return session.getId();
    });
    if (it != gameSessions.end) {
        it->sessionConfigureSettings(sessionSettings);
    }
}

void Owner::kickPlayer(GameSession& session, int playerId) {
    // TODO: Implement remove player method in Session class
    GameSession->removeUserFromSession(playerId);
}

// May not need this method
void Owner::changeOwner(GameSession& session, int newOwnerId) {
    GameSession->setOwnerId(newOwnerId);
}