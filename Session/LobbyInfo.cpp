#include "LobbyInfo.h"

int LobbyInfo:: GeneratePlayerId(std::string gameName, std::string playerName) {
    int id = rand() % 10000; 
    return id;     
}

int LobbyInfo:: AddusersToSessions(int playerId, std::string game) {
    UserIdToGame.insert(std::make_pair(playerId,game));
}

bool LobbyInfo::SessionExists(int inviteCode) {
    if ( SessionToInviteCode.find(inviteCode) == SessionToInviteCode.end()) { 
        return true; 
    }
}

int LobbyInfo::createSession() {
    SessionsInfo newSession;
    SessionsList.push_back(newSession);
    int sessionId = generateSessionID(newSession);
    return sessionId;
}

int LobbyInfo:: generateSessionID(SessionsInfo session) {
    return 123;
}
