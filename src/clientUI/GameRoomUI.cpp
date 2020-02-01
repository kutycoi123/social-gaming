#include "include/GameRoomUI.h"
#include <iostream>
#include <string>


std::string GameRoomUI::getInvitation(){
    std::string invitationCode;
    std::cout << "Please Enter invitation code: \n";
    std:getline(std::cin, invitationCode);
    if (invitationCode.empty()){
        std::cout << "Invitation Code empty, please try again:";
        std::getline(std::cin, invitationCode);
    }
    //return to server
    return invitationCode;
}

std::string GameRoomUI::gameStart(const std::string& input){
    if (_gameConfigValid){
        	std::cout << "Welcome to the game\n";
            //updateServer with the  wwelcome message and instruction of the game
    }
    else{
        //will check for game configuration which has not been met to start the game
        std::cout << "Sorry cannot start the game right now\n";
        //also print the reason like not enough players in the room righ now
        //updateServer
    }
    //return state of the game to server
    return;
}
void GameRoomUI::gameWon(){
    if (gameWon)
    {
        std::cout << "Game Over\n";
        std::cout << "Congratutlations you won\n";
        //updateServer
    }
    else{
        //keep playing the game
        //updateServer
    }
}
std::string GameRoomUI::helpCommand(){
    std::string userInput;
    std::cout <<"Please type 'H' for Help or 'E' to leave the game";
    std::getline(std::cin, userInput);

    return userInput;
}



