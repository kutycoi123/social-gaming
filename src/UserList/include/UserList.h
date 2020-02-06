#include <User.h>
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

    User getUser(const UserId& id);
    bool transferUser(UserList& from, UserList& to);

    std::unordered_map<UserId, User, UserIdHash>::iterator begin();
    std::unordered_map<UserId, User, UserIdHash>::iterator end();


private:
    std::unordered_map<UserId, User, UserIdHash> _idToUserMap; 
};