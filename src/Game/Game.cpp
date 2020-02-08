#include "include/Game.h"

int Game::_counter = 0;

Game::Game() {
    _counter++;
}

int Game::howMany() {
    return _counter;
}