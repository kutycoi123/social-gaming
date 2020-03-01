#include "User.h"

// ***********************
// UserId
// ***********************
UserId::UserId(): _id(-1) {};

UserId::UserId(const uintptr_t& id): _id(id) {};

std::uintptr_t UserId::getId() const {
    return _id;
}

bool UserId::operator==(const UserId& id) const {
    return _id == id.getId();
}

// ***********************
// User
// ***********************
User::User(const UserId& userId):   userId(userId),
                                    userName(UserName("user"+std::to_string(userId.getId()))),
                                    currentGameSessionInvitation(std::nullopt) {};

void User::setUserName(const UserName& name){
	userName = name;
}

void User::setCurrentGameSessionInvitationCode(const Invitation& invite) {
    currentGameSessionInvitation = invite;
}

void User::clearInvitation() noexcept {
    currentGameSessionInvitation = std::nullopt;
}

bool User::isUserInGameSession() const {
    return currentGameSessionInvitation.has_value();
}

std::string User::getUserNameValue() const {
    return userName.name;
}

UserId User::getUserId() const {
    return userId;
}

uintptr_t User::getUserIdValue() const {
    return userId.getId();
}

Invitation User::getCurrentGameSessionInvitation() const {
    return currentGameSessionInvitation.value();
}

