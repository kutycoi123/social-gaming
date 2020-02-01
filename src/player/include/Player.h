#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "../user/include/User.h"
#include "../invitation/include/Invitation.h"


class Player : public User{
    public:
        Player (std::string _name, std::string _id, Invitation& invitation, const std::string& status);
        void setInvitation(Invitation& Invitation);
        Invitation& getInvitation() const;
        void setStatus(const std::string& status);
        std::string getStatus() const;
        void addFriend(const User& user);
        void unfriend(std::string id);

    private:
        Invitation* _invitation;

        //online, off line, away
        std::string _status;

        std::vector<User> _friendlist;
};

#endif