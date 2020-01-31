#include "include/Invitation.h"
#include <iostream>

int main(){
    Invitation i{};
    std::cout << i.getInvitationCode() << std::endl;
}