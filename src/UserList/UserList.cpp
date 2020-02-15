#include "include/UserList.h"
#include "Invitation.h"

UserList::UserList(): _idToUserMap(std::unordered_map<UserId, User, UserIdHash>()) {};

bool UserList::onConnect(const UserId& id) {
    auto user = getUser(id);

    if (user.has_value()) {
        std::cout << " Error, Connecting user is already in UserList." << '\n';
        return false;
    }

    _idToUserMap.insert(std::make_pair(id, User(id)));
    return true;
}

bool UserList::onDisconnect(const UserId& id) {
    auto user = getUser(id);

    if (!user.has_value()) {
        std::cout << " Error, Disconnecting user does not exist in the UserList." << '\n';
        return false;
    }

    _idToUserMap.erase(id);
    return true;
}

std::optional<User> UserList::getUser(const UserId& id) {
    auto iterator = _idToUserMap.find(id);

    if (iterator == _idToUserMap.end()) {
        return std::nullopt;
    }

    return std::optional<User>{iterator->second};
}

User &UserList::getUserRef(const User& user) {
    return _idToUserMap.find(user.getUserId())->second;
}

void UserList::removeUsersFromGameSession(const Invitation& code) {
    std::string codeString = code.toString();
    for (auto& entry : _idToUserMap) {
        if (entry.second.isUserInGameSession(codeString)) {
            entry.second.setCurrentGameSessionInvitationCode(std::string());
        }
    }
}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::begin() {
    return _idToUserMap.begin();
}

std::unordered_map<UserId, User, UserIdHash>::iterator UserList::end() {
    return _idToUserMap.end();
}

size_t UserList::size() const noexcept {
    return _idToUserMap.size();
}
