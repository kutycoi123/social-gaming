#include "include/Invitation.h"
#include <random>
#include <math.h>

Invitation::Invitation(const int& sessionID){
    _sessionID = sessionID;
    _invitationCode = generateInvitationCode();
    _invitationCreationDate = time(0);
}

int Invitation::getSessionId() const {
    return _sessionID;
}

std::string Invitation::getInvitationCode() const {
    return _invitationCode;
}

time_t Invitation::getInvitationCreationDate() const {
    return _invitationCreationDate;
}

std::string Invitation::getGameName() const {
    if (this->isInvitationValid()){
        return INVALID_INVITATION;
    }
    // TODO: Replace this logic with specific session logic once it is implemented
    return "";
}

std::string Invitation::getSessionName() const {
    if (this->isInvitationValid()){
        return INVALID_INVITATION;
    }
    // TODO: Replace this logic with specific session logic once it is implemented
    return "";
}

bool Invitation::isInvitationValid() const {
    // TODO: Replace this logic with actual session logic once it is implemented.
    return true;
}

std::string Invitation::generateInvitationCode(){
    // Returns a random number (as a string) with INVITATION_CODE_LENGTH digits for the invitation code
    std::random_device rd;
    std::mt19937 gen(rd());
    long min = pow(10, INVITATION_CODE_LENGTH - 1);
    long max = pow(10, INVITATION_CODE_LENGTH) - 1;
    std::uniform_int_distribution<long> dis(min, max);
    return std::to_string(dis(gen));
}