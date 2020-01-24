#include <string>

class Invitation {
public:
    Invitation(const int& sessionID);
    int GetSessionId();
    std::string GetInvitationCode();

private:
    // TODO: replace session id with appropriate class once it is complete
    // Session session;
    int _sessionID;
    const int INVITATION_CODE_LENGTH = 1;
    std::string _invitationCode;
    std::string GenerateInvitationCode();
};