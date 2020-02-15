#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>

// TODO MZEGAR: Things to consider in the future
// 1. Some point system? "global information will be displayed to all players on the main game screen."
// 2. Check to see if a player has already created a game
// 4. Some icon system? country system?
// 5. Consider storing some connection info here or having this User class be a child of the web-socket-client

struct UserName {
    std::string name;
};

enum privilage {
    user, owner, serverAdmin 
};

class UserId {
public:
    UserId();
    UserId(const uintptr_t& id);
    uintptr_t getId() const;
    bool operator==(const UserId& id) const;

private:
    uintptr_t _id;
    
};

class User {
public:
    User(const UserId& userId);

    void setName(const UserName& name);
    void setPrivilage(privilage type);
    UserName getName() const;
    uintptr_t getUserId() const;
    bool operator==(const User& user) const {
        return getUserId() == user.getUserId();
    }

private:
    UserName _userName;
    UserId _userId;
    privilage Type;

};



#endif