#ifndef INVITATION_H
#define INVITATION_H

#include <string>

class Invitation {
public:
    Invitation();
    std::string getInvitationCode() const;
    bool isInvitationValid() const;
private:
    const int INVITATION_CODE_LENGTH = 8;
    const std::string INVALID_INVITATION = "Invitation is not valid!";
    std::string _invitationCode;
    std::string generateInvitationCode();
};

#endif