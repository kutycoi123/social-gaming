#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
<<<<<<< HEAD
#include "User.h"
#include "Invitation.h"

=======
#include "../../user/include/User.h"
#include "../../invitation/include/Invitation.h"
#include<bits/stdc++.h> 
>>>>>>> 934dd06a0ce8f58ef9b347462226443bea00c836

class Player : public User{
    public:
        Player (std::string _name, std::string _id, Invitation& invitation, const std::string& status);
        void setInvitation(Invitation& Invitation);
        void setInvitationCode(std::string _invitaionCode);
        Invitation& getInvitation() const;
        void setStatus(const std::string& status);
        std::string getStatus() const;
        void addFriend(const User& user);
        void unfriend(std::string id);

    private:
        Invitation *_invitation;
        std::string _invitaionCode;
        //online, off line, away
        std::string _status;

        std::vector<User> _friendlist;
};

#endif