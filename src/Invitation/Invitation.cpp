#include "include/Invitation.h"
// #include "GameSessionManager.h"
#include <random>
#include <math.h>

Invitation::Invitation() : _invitationCode( generateInvitationCode() )
    {}

Invitation::Invitation(std::string invitationCode) : _invitationCode( invitationCode )  
    {}

std::string Invitation::toString() const {
    return _invitationCode;
}

std::string Invitation::generateInvitationCode(){
    // Returns a random number (as a string) with INVITATION_CODE_LENGTH digits for the invitation code
    std::random_device rd;
    std::mt19937 gen(rd());
    long min = pow(10, INVITATION_CODE_LENGTH - 1);
    long max = pow(10, INVITATION_CODE_LENGTH) - 1;
    std::uniform_int_distribution<long> dis(min, max);
    auto inviteCode = std::to_string(dis(gen));
    while (false){ // TODO : Replace this stub with GameSessionManager logic
        inviteCode = std::to_string(dis(gen));
    }
    return inviteCode;
}