#include "include/User.h"

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
User::User(const UserId& userId): userId(userId), userName(UserName("user"+std::to_string(userId.getId()))) {};

void User::setUserName(const UserName& name){
	userName = name;
}

void User::setCurrentGameSessionInvitationCode(const std::string& code) {
    currentGameSessionInvitationCode = code;
}

void User::setPrivilage(privilage type){
	this->Type = type;
}

bool User::isUserInGameSession(const std::string& code) const {
    return !currentGameSessionInvitationCode.empty() && currentGameSessionInvitationCode == code;
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

std::string User::getCurrentGameSessionInvitationCode() const {
    return currentGameSessionInvitationCode;
}

