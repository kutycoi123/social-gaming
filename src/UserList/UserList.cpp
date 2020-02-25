#include "include/UserList.h"

UserList::UserList() {};

void UserList::addUser(const UserId& id) {
    idToUserMap.insert(std::make_pair(id, User(id)));
}

void UserList::removeUser(const UserId& id) {
    idToUserMap.erase(id);
}

void UserList::removeAllUsers() {
    idToUserMap.clear();
}

std::optional<User> UserList::getUser(const UserId& id) {
    auto iterator = idToUserMap.find(id);

    if (iterator == idToUserMap.end()) {
        return std::nullopt;
    }

    return std::optional<User>{iterator->second};
}

bool UserList::transferUser(UserList& transferTo, User& user) {
    UserId userId = user.getUserId();
    auto iterator = idToUserMap.find(userId);

    if (iterator != idToUserMap.end()) {
        removeUser(userId);
        transferTo.addUser(userId);
        return true;
    } else {
        return false;
    }
}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::begin() {
    return idToUserMap.begin();
}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::end() {
    return idToUserMap.end();
}

size_t UserList::size() const noexcept {
    return idToUserMap.size();
}