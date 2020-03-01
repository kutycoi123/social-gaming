#include "GameSession.h"
#include "Invitation.h"
#include "User.h"
#include "UserList.h"
#include <unordered_map>
#include <list>
#include <optional>
#include <sstream>
#include <algorithm>

struct Message {
    User user;
    std::string payload;
};

class GameSessionList {
    public:
        GameSessionList();
        
        bool joinGameSession(std::reference_wrapper<User>& userRef, const Invitation& invitation) noexcept;
        bool leaveGameSession(std::reference_wrapper<User>& userRef, const Invitation& invitation) noexcept;
        
        Invitation createGameSession(User& owner) noexcept;
        void destroyGameSession(const Invitation& invitation) noexcept;

        bool startGameInGameSession(const Invitation& invitation);

        void addMessages(const std::list<Message> messages) noexcept;
        std::list<Message> updateAndGetAllMessages() noexcept;
    
    private:
	    struct InvitationHash {
            std::size_t operator()(const Invitation& invitation) const {
                return std::hash<std::string>()(invitation.toString());
            }
        };

        struct UserIdHash {
            std::size_t operator()(const UserId& id) const {
                //casting uintptr to string
                std::stringstream stream;
                stream << id.getId();
                
                return std::hash<std::string>()(stream.str());
            }
        };

        std::list<GameSession> sessionList;
        std::list<Message> messageBuffer;

        std::unordered_map<UserId, Invitation, UserIdHash> user2InviteCode;
        std::unordered_map<Invitation, std::vector<UserId>, InvitationHash> inviteCode2User;


        std::list<GameSession>::iterator findGameSession(const Invitation&) noexcept;
        void addToUserInviteCodeMaps(const UserId&, const Invitation&) noexcept;
        void removeFromUserInviteCodeMaps(const UserId&, const Invitation&) noexcept;
        void addMessageToCorrectSession(const Message&) noexcept;
};