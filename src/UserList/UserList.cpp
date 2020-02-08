#include "include/UserList.h"

UserList::UserList() {};

void UserList::addUser(const UserId& id) {
    _idToUserMap.insert(std::make_pair(id, User(id)));
}

void UserList::removeUser(const UserId& id) {
    _idToUserMap.erase(id);
}

std::optional<User> UserList::getUser(const UserId& id) {
    auto iterator = _idToUserMap.find(id);

    if (iterator == _idToUserMap.end()) {
        return std::nullopt;
    }

    return std::optional<User>{iterator->second};
}

bool UserList::transferUser(UserList& transferTo, User& user) {
    UserId userId = user.getUserId();
    auto iterator = _idToUserMap.find(userId);

    if (iterator != _idToUserMap.end()) {
        removeUser(userId);
        transferTo.addUser(userId);
        return true;
    } else {
        return false;
    }
}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::begin() {
    return _idToUserMap.begin();
}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::end() {
    return _idToUserMap.end();
}