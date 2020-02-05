#ifndef INVITATION_H
#define INVITATION_H

#include <string>

class Invitation {
public:
    Invitation();
    Invitation(std::string invitationCode);
    std::string toString() const;
private:
    const int INVITATION_CODE_LENGTH = 8;
    std::string _invitationCode;
    std::string generateInvitationCode();
};

#endif