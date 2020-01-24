#include "Invitation.h"
#include <random>
#include <math.h>

Invitation::Invitation(const int& sessionID){
    _sessionID = sessionID;
    _invitationCode = GenerateInvitationCode();
}

int Invitation::GetSessionId(){
    return _sessionID;
}

std::string Invitation::GetInvitationCode(){
    return _invitationCode;
}

std::string Invitation::GenerateInvitationCode(){
    // Returns a random number (as a string) with INVITATION_CODE_LENGTH digits for the invitation code
    std::random_device rd;
    std::mt19937 gen(rd());
    long min = pow(10, INVITATION_CODE_LENGTH - 1);
    long max = pow(10, INVITATION_CODE_LENGTH) - 1;
    std::uniform_int_distribution<long> dis(min, max);
    return std::to_string(dis(gen));
}