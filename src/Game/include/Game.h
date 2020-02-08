#ifndef GAME_H
#define GAME_H

#include <string>
#include <nlohmann/json.hpp>

class Game {
public:
    Game(nlohmann::json gameSettings);
};

#endif