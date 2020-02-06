#include "include/User.h"

UserId::UserId(const uintptr_t& id) {
    _id = id;
}

std::uintptr_t UserId::getId() const {
    return _id;
}

bool UserId::operator==(const UserId& id) const {
    return _id == id.getId();
}

User::User(const uintptr_t& id) {
    _id = id;
}

// User::User(const std::string& name, const std::string& id, const Game& currentGame) {
//      _name = name;
//      _id = id;
//      _currentGame = currentGame;
// }

// void User::setCurrentGame(const Game& game) {
//      _currentGame = game;
// }

std::string User::getName() const{
    return _name;
}

std::uintptr_t User::getId() const{
    return _id;
}

// Game User::getCurrentGame() {
//      return _currentGame;
// }

void User::setName(const std::string& name){
	_name = name;
}