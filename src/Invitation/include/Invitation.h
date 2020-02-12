#ifndef INVITATION_H
#define INVITATION_H

#include <string>

class Invitation {
public:
    std::string toString() const;
    static Invitation createNewInvitation(){
        return Invitation();
    };

    static Invitation createInvitationFromStringInput(const std::string& invitationCode){
        return Invitation(invitationCode);
    }

    bool operator==(const Invitation& invitation ) const {
        return _invitationCode.compare(invitation.toString()) == 0;
    }
private:
    Invitation();
    explicit Invitation(const std::string& invitationCode);
    static unsigned long count;
    const std::string SEPARATOR = "x";
    const size_t MINIMUM_COUNT_STRING_LENGTH = 3;
    const size_t RANDOM_CODE_LENGTH = 3;
    const size_t MINIMUM_LENGTH = MINIMUM_COUNT_STRING_LENGTH + RANDOM_CODE_LENGTH + SEPARATOR.length();
    std::string _invitationCode;
    std::string generateInvitationCode();
};

#endif