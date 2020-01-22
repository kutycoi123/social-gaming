#include <string>

// TODO MZEGAR: Things to consider in the future
// 1. Some point system? "global information will be displayed to all players on the main game screen."
// 2. Check to see if a player has already created a game
// 3. CurrentGameId/Name might not be needed
// 4. Some icon system? country system?
// 5. Consider storing some connection info here or having this User class be a child of the web-socket-client

class User {
public:
    User(const std::string& name, const int& id);

    void SetCurrentGame(const std::string& gameName, const int& gameId);

    std::string GetName();
    int GetId();

    std::string GetCurrentGameName();
    int GetCurrentGameId();

private:
    std::string _name;
    int _id;

    std::string _currentGameName;
    int _currentGameId;
};