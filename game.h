#ifndef GAME_H
#define GAME_H

#define WINNING_VALUE 2048

#include "board.h"


class Game
{
public:
    Game(int dimension);
    ~Game();
    void restart();
    bool isGameOver() const { return gameOver; }
    Board* getGameBoard() const { return board; }
    void registerObserver(QGameBoard* observer);
    void move(Direction dir);
    // returns true if the game is in the win state,
    // (i.e. there is a tile that has the value as defined in WINNING_VALUE)
    bool won() const;
    int getScore() const { return score; }
    int getHighScore() const {return highscore;}
    void readHighScore();
    void saveHighScore();

private:
    Board* board;
    bool gameOver;
    int score;
    int highscore;

};

#endif // GAME_H
