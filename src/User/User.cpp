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
User::User(const UserId& userId): userId(userId) {};

UserName User::getName() const{
    return userName;
}

uintptr_t User::getUserId() const{
    return userId.getId();
}

void User::setName(const UserName& name){
	userName = name;
}

void User::setPrivilage(privilage type){
	this->Type = type;
}

