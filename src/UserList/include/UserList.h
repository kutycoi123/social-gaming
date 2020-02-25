#ifndef USERLIST_H
#define USERLIST_H

#include <User.h>
#include <optional>
#include <unordered_map>

struct UserIdHash
{
    size_t operator()(const UserId& id) const { 
        return std::hash<uintptr_t>()(id.getId());
    } 
};

class UserList {
public:
    UserList();
    void addUser(const UserId& id);
    void removeUser(const UserId& id);
    void removeAllUsers();

    std::optional<User> getUser(const UserId& id);
    bool transferUser(UserList& transferTo, User& user);

    std::unordered_map<UserId, User, UserIdHash>::iterator begin();
    std::unordered_map<UserId, User, UserIdHash>::iterator end();

    size_t size() const noexcept;
private:
    std::unordered_map<UserId, User, UserIdHash> idToUserMap; 
};

#endif