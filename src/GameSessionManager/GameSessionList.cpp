#include "GameSessionList.h"

GameSessionList::GameSessionList() : 
    sessionList({}),
    user2InviteCode({}),
    inviteCode2User({}) {}

bool GameSessionList::joinGameSession(std::reference_wrapper<User>& userRef, const Invitation& invitation) noexcept{
    auto gameSession = findGameSession(invitation);

    //if session exists and the game has not started, then user can join
    if(gameSession != sessionList.end() && !gameSession->isGameStarted()){
        userRef.get().setCurrentGameSessionInvitationCode(invitation);
        return true;
    }

    return false;
}

bool GameSessionList::leaveGameSession(std::reference_wrapper<User>& userRef, const Invitation& invitation) noexcept{
    auto gameSession = findGameSession(invitation);

    if(gameSession != sessionList.end() && !gameSession->isGameStarted()){
        userRef.get().clearInvitation();
        return true;
    }

    return false;
}

Invitation GameSessionList::createGameSession(User& owner) noexcept{
    GameSession gameSession{owner};
    sessionList.push_back(gameSession);
    return gameSession.getInvitationCode();
}

void GameSessionList::destroyGameSession(const Invitation& invitation) noexcept{
    auto session = findGameSession(invitation);
    
    if (session != sessionList.end()){
        //sessionList.erase(session);
    }
}

std::deque<networking::Message> GameSessionList::getAllSessionMessages() const noexcept{
    return {};
}


bool GameSessionList::startGameInGameSession(const Invitation& invitation){
    auto gameSession = findGameSession(invitation);
    
    if (gameSession != sessionList.end()){
        gameSession->startGame();
        return true;
    }

    return false;
}

// Finds corresponding game session to provided Invitation code
// Returns the GameSession if one is found or an empty optional if none is found 
std::vector<GameSession>::iterator GameSessionList::findGameSession(const Invitation& invitation){
    return std::find_if(sessionList.begin(), sessionList.end(), [invitation](const GameSession& session){
        return session.getInvitationCode().toString() == invitation.toString();
    });
}

void GameSessionList::addToUserInviteCodeMaps(const UserId& id, const Invitation& invite) noexcept{
    user2InviteCode.insert(std::make_pair(id, invite));

    auto userList = std::find_if(inviteCode2User.begin(), inviteCode2User.end(), [invite](const std::pair<Invitation, std::vector<UserId>>& val){
        return val.first.toString() == invite.toString();
    });

    if(userList == inviteCode2User.end()){
        inviteCode2User.insert(std::make_pair(invite, std::vector<UserId>({id})));
    }
    else {
        userList->second.push_back(id);
    }
}

void GameSessionList::removeFromUserInviteCodeMaps(const UserId& id, const Invitation& invite) noexcept{
    auto userId = std::find_if(user2InviteCode.begin(), user2InviteCode.end(), [id](const std::pair<UserId, Invitation>& entry){
        return entry.first.getId() == id.getId();
    });

    user2InviteCode.erase(userId);

    auto userList = std::find_if(inviteCode2User.begin(), inviteCode2User.end(), [invite](const std::pair<Invitation, std::vector<UserId>>& val){
        return val.first.toString() == invite.toString();
    });

    if(userList->second.size() <= 1){
        inviteCode2User.erase(userList);
    }
    else {
        userList->second.erase(std::find(userList->second.begin(), userList->second.end(), id));
    }
    

}
    