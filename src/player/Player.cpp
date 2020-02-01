#include "include/Player.h"

Player::Player (std::string _name, std::string _id, Invitation& invitation, const std::string& status) : User(_name, _id) {
    _invitation = &invitation;
    _status = status;
}

void Player::setInvitation(Invitation &invitation){
    _invitation = &invitation;
}

Invitation& Player::getInvitation() const{
    return *_invitation;
}


void Player::setStatus(const std::string& status){
    _status = status;
}

std::string Player::getStatus() const{
    return _status;
}

void Player::addFriend(const User& user){
<<<<<<< HEAD
    bool contain = false;
    for (std::size_t i = 0; i < _friendlist.size(); i++){
        if(_friendlist[i].getId == user.getId())
            break;
=======
    if (std::find(_friendlist.begin(), _friendlist.end(), user) == _friendlist.end()) {
        _friendlist.push_back(user);
>>>>>>> 934dd06a0ce8f58ef9b347462226443bea00c836
    }
    if (contain == false)
        _friendlist.push_back(user);
}

void Player::unfriend(std::string id){
    for (std::size_t i = 0; i < _friendlist.size(); i++){
        if(_friendlist[i].getId == id){
            _friendlist.erase(_friendlist.begin()+i);
            break;
        }
    }
}
