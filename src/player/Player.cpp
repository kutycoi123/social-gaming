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
    return this->_status;
}

void Player::addFriend(const User& user){
    if (std::find(_friendlist.begin(), _friendlist.end(), user) == _friendlist.end()) {
        _friendlist.push_back(user);
    }
}

void Player::unfriend(std::string id){
    for (std::size_t i = 0; i < _friendlist.size(); i++){
        if(_friendlist[i].getId == id){
            _friendlist.erase(_friendlist.begin()+i);
            break;
        }
    }
}