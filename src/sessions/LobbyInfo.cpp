#include "include/LobbyInfo.h"

int LobbyInfo:: generatePlayerId(std::string gameName, std::string playerName) {
    int id = rand() % 10000; 
    return id;     
}

int LobbyInfo:: addusersToSessions(int playerId, std::string game) {
    UserIdToGame.insert(std::make_pair(playerId,game));
    return 0;
}

bool LobbyInfo::sessionExists(int inviteCode) {
    if ( SessionToInviteCode.find(inviteCode) == SessionToInviteCode.end()) { 
        return true; 
    }
    return false;
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
