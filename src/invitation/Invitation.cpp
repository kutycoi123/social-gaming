#include "include/Invitation.h"
#include <random>
#include <math.h>

Invitation::Invitation() : _invitationCode( generateInvitationCode() )
    {}

std::string Invitation::getInvitationCode() const {
    return _invitationCode;
}

bool Invitation::isInvitationValid() const {
    return true;
}

std::string Invitation::generateInvitationCode(){
    std::random_device rd;
    std::mt19937 gen(rd());
    long min = pow(10, INVITATION_CODE_LENGTH - 1);
    long max = pow(10, INVITATION_CODE_LENGTH) - 1;
    std::uniform_int_distribution<long> dis(min, max);
    return std::to_string(dis(gen));
}