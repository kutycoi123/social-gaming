#include "include/Player.h"

    

void Player::setInvitation(Invitation& invitation1){
    _invitation = &invitation1;
}

Invitation& Player::getInvitation() const{
    return *_invitation;
}

void Player::setStatus(const std::string& status1){
    _status = status1;
}

std::string Player::getStatus() const{
    return _status;
}

void Player::addFriend(const User& user){
    bool contain = false;
    for (std::size_t i = 0; i < _friendlist.size(); i++){
        if(_friendlist[i].getId == user.getId())
            contain = true;
            break;
    }
    
    if (contain = false)
        _friendlist.push_back(user);
    
}

void Player::unfriend(std::string id){
    for (std::size_t i = 0; i < _friendlist.size(); i++){
        if(_friendlist[i].getId == id)
            _friendlist.erase(_friendlist.begin()+i);
            break;
    }
}