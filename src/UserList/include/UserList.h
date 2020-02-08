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

    std::optional<User> getUser(const UserId& id);
    bool transferUser(UserList& transferTo, User& user);

    std::unordered_map<UserId, User, UserIdHash>::iterator begin();
    std::unordered_map<UserId, User, UserIdHash>::iterator end();


private:
    std::unordered_map<UserId, User, UserIdHash> _idToUserMap; 
};