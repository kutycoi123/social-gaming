#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState {
public:
    GameState();
    bool isGameStarted() const;
    void startGame();
private:
    bool gameStarted;
};


#endif
