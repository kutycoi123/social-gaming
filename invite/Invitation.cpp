#include "Invitation.h"
#include <random>
#include <math.h>

Invitation::Invitation(const int& sessionID){
    _sessionID = sessionID;
    // TODO: replace placeholder invitation stub with actual code
    _invitationCode = GenerateInvitationCode();
}

int Invitation::GetSessionId(){
    return _sessionID;
}

std::string Invitation::GetInvitationCode(){
    return _invitationCode;
}

std::string Invitation::GenerateInvitationCode(){
    std::random_device rd;
    std::mt19937 gen(rd());
    long min = pow(10, INVITATION_CODE_LENGTH - 1);
    long max = pow(10, INVITATION_CODE_LENGTH) - 1;
    std::uniform_int_distribution<long> dis(min, max);
    return std::to_string(dis(gen));
}