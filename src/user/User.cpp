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

std::string User::GetName() {
    return _name;
}

std::string User::GetId() {
    return _id;
}

// Game User::GetCurrentGame() {
//     return _currentGame;
// }