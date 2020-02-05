#include <iostream>
#include <string>

class GameRoomUI{
    public:
        std::string playerInvitationCode(){};
        bool checkPlayerInput(){};
        bool playerValidity(){};
        void updateServer(){};
        std::string gameStart(const std::string& input){};
        void gameWon (){};
        std::string helpCommand (){};

    private:
        bool _gameConfigValid = true;
        bool _gameStatus = true;
};
