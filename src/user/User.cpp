#include "User.h"

User::User(const std::string& name, const std::string& id) {
    _name = name;
    _id = id;
}

// User::User(const std::string& name, const std::string& id, const Game& currentGame) {
//     _name = name;
//     _id = id;
//     _currentGame = currentGame;
// }

// void User::SetCurrentGame(const Game& game); {
//     _currentGame = game;
// }

std::string User::GetName() const{
    return _name;
}

std::string User::GetId() const{
    return _id;
}

// Game User::GetCurrentGame() {
//     return _currentGame;
// }


void User::SetName(const std::string& name){
	_name = name;
}

void User::SetId(const std::string& id){
	_id = id;
}
