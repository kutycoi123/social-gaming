#ifndef USER_H
#define USER_H

#include "Invitation.h"
#include <string>
#include <unordered_map>
#include <utility>

class UserName {
public:
    explicit UserName(std::string  stringName) : name(std::move(stringName)) {};
    std::string name;
};

class UserId {
public:
    UserId();
    explicit UserId(const uintptr_t& id);
    [[nodiscard]] uintptr_t getId() const;
    bool operator==(const UserId& id) const;

private:
    uintptr_t _id;
    
};

class User {
public:
    explicit User(const UserId& userId);

    void setUserName(const UserName& name);
    void setCurrentGameSessionInvitationCode(const Invitation& invite);

    [[nodiscard]] bool isUserInGameSession(const Invitation& invite) const;

    [[nodiscard]] std::string getUserNameValue() const;
    [[nodiscard]] UserId getUserId() const;
    [[nodiscard]] uintptr_t getUserIdValue() const;
    [[nodiscard]] Invitation getCurrentGameSessionInvitation() const;

    bool operator==(const User& user) const {
        return getUserIdValue() == user.getUserIdValue();
    }

private:
    UserId userId;
    UserName userName;
    Invitation currentGameSessionInvitation;
};



#endif