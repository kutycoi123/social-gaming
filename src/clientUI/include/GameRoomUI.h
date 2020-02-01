#include <iostream>
#include <string>

class GameRoomUI{
    public:

        std::string getInvitation(){};
        
        bool checkPlayerInput(){};
        bool playerValidity(){};
        void updateServer(){};
        std::string gameStart(const std::string& input){};
        void gameWon (){};
        std::string helpCommand (){};

    private:
        bool _gameConfigValid = true;
        bool _gameWon = true;
};
