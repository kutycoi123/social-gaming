#include <string>

class Invitation {
public:
    Invitation(const int& sessionID);
    int GetSessionId() const;
    time_t GetInvitationCreationDate() const;
    std::string GetInvitationCode() const;
    std::string GetSessionName() const;
    std::string GetGameName() const;
    bool IsInvitationValid() const;
private:
    // TODO: replace session id with appropriate class once it is complete
    // Session session;
    int _sessionID;
    const int INVITATION_CODE_LENGTH = 8;
    const std::string INVALID_INVITATION = "Invitation is not valid!";
    time_t _invitationCreationDate;
    std::string _invitationCode;
    std::string GenerateInvitationCode();
};