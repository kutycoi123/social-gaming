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
User::User(const UserId& userId): _userId(userId) {};

UserName User::getName() const{
    return _userName;
}

uintptr_t User::getUserId() const{
    return _userId.getId();
}

void User::setName(const UserName& name){
	_userName = name;
}