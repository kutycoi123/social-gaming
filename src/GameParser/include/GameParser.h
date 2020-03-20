
#ifndef GAME_PARSER_H
#define GAME_PARSER_H
 
#include <list>
#include <nlohmann/json.hpp>

#include <cassert>
#include <fstream>
#include <string>
#include <vector>

#include "Game.h"

class GameParser{
    public:
        //The constructor should take in a string which is the filepath of the appropriate Game JSON, create the game, and store the game in a member variable
        GameParser(const std::string&);
        //This returns the Game object that was created by the Constructor
        //Unique ptr gets returned and reset so this object should be deleted after because it should be useless
        std::unique_ptr<Game> getGame() noexcept;

    private:
        nlohmann::json fileToJson(const std::string& pathName);

        std::unique_ptr<Game> game;
        bool hasGame;
};
#endif
