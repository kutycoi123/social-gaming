#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>

enum privilage {
    user, owner, serverAdmin 
};

class UserName {
public:
    UserName(const std::string& stringName) : name(stringName) {};
    std::string name;
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

    void setUserName(const UserName& name);
    void setCurrentGameSessionInvitationCode(const std::string& code);
    void setPrivilage(privilage type);

    bool isUserInGameSession(const std::string& code) const;

    std::string getUserNameValue() const;
    UserId getUserId() const;
    uintptr_t getUserIdValue() const;
    std::string getCurrentGameSessionInvitationCode() const;

    bool operator==(const User& user) const {
        return getUserIdValue() == user.getUserIdValue();
    }

private:
    UserName userName;
    UserId userId;

    // TODO: Consider changing this to an invitation object using the second constructor
    std::string currentGameSessionInvitationCode;
    privilage Type;
};



#endif