#include <string>

class Invitation {
public:
    Invitation(const int& sessionID);
    int GetSessionId() const;
    time_t GetInvitationCreationDate() const;
    std::string GetInvitationCode() const;
    bool IsInvitationValid();
private:
    // TODO: replace session id with appropriate class once it is complete
    // Session session;
    int _sessionID;
    const int INVITATION_CODE_LENGTH = 8;
    time_t _invitationCreationDate;
    std::string _invitationCode;
    std::string GenerateInvitationCode();
};