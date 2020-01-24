#include "Invitation.h"

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
    std::string s0("");
    // Will implement logic to create randomized strings
    return s0;
}