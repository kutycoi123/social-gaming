#include "include/UserList.h"
#include "Invitation.h"

UserList::UserList(): idToUserMap(std::unordered_map<UserId, User, UserIdHash>()) {};

bool UserList::onConnect(const UserId& id) {
    auto user = getUser(id);

    if (user.has_value()) {
        std::cout << " Error, Connecting user is already in UserList." << '\n';
        return false;
    }

    idToUserMap.insert(std::make_pair(id, User(id)));
    return true;
}

bool UserList::onDisconnect(const UserId& id) {
    auto user = getUser(id);

    if (!user.has_value()) {
        std::cout << " Error, Disconnecting user does not exist in the UserList." << '\n';
        return false;
    }

    idToUserMap.erase(id);
    return true;
}

std::optional<User> UserList::getUser(const UserId& id) {
    auto iterator = idToUserMap.find(id);

    if (iterator == idToUserMap.end()) {
        return std::nullopt;
    }

    return std::optional<User>{iterator->second};
}

// The returned pointer should never outlive the scope of the caller function
std::optional<std::reference_wrapper<User>> UserList::getUserRef(const UserId& id) {
    auto iterator = idToUserMap.find(id);
    return std::optional<std::reference_wrapper<User>>{iterator->second};
}

void UserList::removeUsersFromGameSession(const Invitation& code) {
    auto usersInSession = getUsersInSession(code);
    for (auto& user : usersInSession) {
        user.get().setCurrentGameSessionInvitationCode(std::string());
    }
}

std::vector<std::reference_wrapper<User>> UserList::getUsersInSession(const Invitation& code) {
    std::string codeString = code.toString();
    std::vector<std::reference_wrapper<User>> users;
    for (auto& entry : idToUserMap) {
        if (entry.second.isUserInGameSession(codeString)) {
            users.emplace_back(entry.second);
        }
    }

    return users;
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
