#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "User.h"
#include "Invitation.h"

class Player : public User{
    public:
        Player (const Invitation& invitation, const std::string& status);
        void setInvitation(const Invitation& Invitation);
        Invitation getInvitation() const;
        void setStatus(const std::string& status);
        std::string getStatus() const;
        void addFriend(const User& user);
        void unfriend(std::string id);

    private:
        Invitation invitation;

        //online, off line, away
        std::string status;

        std::vector<User> friendlist;
};

#endif