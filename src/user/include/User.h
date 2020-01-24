#ifndef USER_H
#define USER_H

#include <string>

// TODO MZEGAR: Things to consider in the future
// 1. Some point system? "global information will be displayed to all players on the main game screen."
// 2. Check to see if a player has already created a game
// 4. Some icon system? country system?
// 5. Consider storing some connection info here or having this User class be a child of the web-socket-client

class User {
public:
    User(const std::string& name, const std::string& id);
    User(const std::string& name, const std::string& id, const Game& currentGame);

    Game getCurrentGame() const;
    std::string getName() const;
    std::string getId() const;

	void setName(const std::string& name);
	void setId(const std::string& id); 
    void setCurrentGame(const Game& game);

private:
    std::string _name;
    std::string _id;
    Game _currentGame = nullptr;
};


#endif
