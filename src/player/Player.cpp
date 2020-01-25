#include "include/Player.h"

Player::Player(const Invitation& invitation1, const std::string& status1){
    invitation = invitation1;
    status = status1;
}

void Player::setInvitation(const Invitation& invitation1){
    invitation = invitation1;
}

Invitation Player::getInvitation() const{
    return invitation;
}

void Player::setStatus(const std::string& status1){
    status = status1;
}

std::string Player::getStatus() const{
    return status;
}

void Player::addFriend(const User& user){
    friendlist.push_back(user);
}

void Player::unfriend(std::string id){
    for (std::size_t i = 0; i < friendlist.size(); i++){
        if(friendlist[i].getId == id)
            friendlist.erase(friendlist.begin()+i);
    }
}