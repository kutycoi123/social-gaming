#include "include/GameSession.h"
#include <iostream>

int main(){
    GameSession i{};
    std::cout << i.getInvitationCode() << std::endl;
}