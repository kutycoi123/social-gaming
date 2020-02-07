#include "include/Game.h"

int Game::_counter = 0;

Game::Game() : id(_counter) {
    _counter++;
}

int Game::howMany() {
    return _counter;
}