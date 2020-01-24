#include <string>

class Invitation {
public:
    Invitation(const int& sessionID);
    int getSessionId() const;
    time_t getInvitationCreationDate() const;
    std::string getInvitationCode() const;
    std::string getSessionName() const;
    std::string getGameName() const;
    bool isInvitationValid() const;
private:
    // TODO: replace session id with appropriate class once it is complete
    // Session session;
    int _sessionID;
    const int INVITATION_CODE_LENGTH = 8;
    const std::string INVALID_INVITATION = "Invitation is not valid!";
    time_t _invitationCreationDate;
    std::string _invitationCode;
    std::string generateInvitationCode();
};