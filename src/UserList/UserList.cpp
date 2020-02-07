#include "include/UserList.h"
#include <iostream>

UserList::UserList() {};

void UserList::addUser(const UserId& id) {
    _idToUserMap.insert(std::make_pair(id, User(id)));
}

void UserList::removeUser(const UserId& id) {
    _idToUserMap.erase(id);
}

User UserList::getUser(const UserId& id) {
    auto iterator = _idToUserMap.find(id);

    if (iterator != _idToUserMap.end()) {
        return iterator->second;
    } else {
        throw std::runtime_error("no such user");
    }
}

bool UserList::transferUser(UserList& from, UserList& to, User& user) {

}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::begin() {
    return _idToUserMap.begin();
}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::end() {
    return _idToUserMap.end();
}