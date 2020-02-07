#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    Game();
    int howMany();

private:
    static int _counter;
};

#endif