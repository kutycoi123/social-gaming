#ifndef INVITATION_H
#define INVITATION_H

#include <string>

class Invitation {
public:
    Invitation();
    explicit Invitation(const std::string& invitationCode);
    std::string toString() const;

    bool operator==(const Invitation& invitation ) const {
        return _invitationCode.compare(invitation.toString()) == 0;
    }
private:
    static unsigned long count;
    const std::string SEPARATOR = "x";
    const size_t MINIMUM_COUNT_STRING_LENGTH = 3;
    const size_t RANDOM_CODE_LENGTH = 3;
    const size_t MINIMUM_LENGTH = MINIMUM_COUNT_STRING_LENGTH + RANDOM_CODE_LENGTH + SEPARATOR.length();
    std::string _invitationCode;
    std::string generateInvitationCode();
};

#endif