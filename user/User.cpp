#include "User.h"

User::User(const std::string& name, const int& id) {
    _name = name;
    _id = id;
}

void User::SetCurrentGame(const std::string& gameName, const int& gameId) {
    _currentGameName = gameName;
    _currentGameId = gameId;
}

std::string User::GetName() {
    return _name;
}

int User::GetId() {
    return _id;
}

std::string User::GetCurrentGameName() {
    if (!_currentGameName.empty())
    {
        return _currentGameName;
    }

    return std::string();
}

int User::GetCurrentGameId() {
    if (!GetCurrentGameName().empty)
    {
        return _currentGameId;
    }

    return -1;
}