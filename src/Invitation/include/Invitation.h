#ifndef INVITATION_H
#define INVITATION_H

#include <string>

class Invitation {
public:
    Invitation();
    explicit Invitation(std::string invitationCode);
    std::string toString() const;

    bool operator==(const Invitation& invitation ) const {
        return _invitationCode.compare(invitation.toString()) == 0;
    }
private:
    const size_t INVITATION_CODE_LENGTH = 8;
    std::string _invitationCode;
    std::string generateInvitationCode();
};

#endif