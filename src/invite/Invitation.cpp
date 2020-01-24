#include "include/Invitation.h"
#include <random>
#include <math.h>

Invitation::Invitation(const int& sessionID){
    _sessionID = sessionID;
    _invitationCode = GenerateInvitationCode();
    _invitationCreationDate = time(0);
}

int Invitation::GetSessionId() const {
    return _sessionID;
}

std::string Invitation::GetInvitationCode() const {
    return _invitationCode;
}

time_t Invitation::GetInvitationCreationDate() const {
    return _invitationCreationDate;
}

std::string Invitation::GetGameName() const {
    return this->IsInvitationValid() ? INVALID_INVITATION : "";
        return INVALID_INVITATION;
    }
    // TODO: Replace this logic with specific session logic once it is implemented
    return "";
}

std::string Invitation::GetSessionName() const {
    if (this->IsInvitationValid()){
        return INVALID_INVITATION;
    }
    // TODO: Replace this logic with specific session logic once it is implemented
    return "";
}

bool Invitation::IsInvitationValid() const {
    // TODO: Replace this logic with actual session logic once it is implemented.
    return true;
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