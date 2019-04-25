#ifndef BOARD_H
#define BOARD_H


#include <QVector>
#include <QString>
#include <vector>
#include "qgameboard.h"
using namespace std;

class Tile;

enum Direction { UP, DOWN, LEFT, RIGHT };

class Board
{
public:

    Board(int dimension);
    Board(const Board& other);
    // destroy board
    ~Board();
    // put the board in start state (everything empty except for two 2 tiles)
    void reset();
    void notifyObservers();
    void registerObserver(QGameBoard* observer);
    Tile* getTile(int i, int j);
    int getDimension() const { return dimension; }
    void move(Direction direction);
    bool full() const;
    int getPointsScoredLastRound() const { return pointsScoredLastRound; }
    bool isTileCollisionLastRound() const { return tileCollisionLastRound; }
    // is there still a move possible
    bool movePossible() const;

private:
    vector<QGameBoard*> observers;
    QVector<QVector<Tile*> > board;
    int dimension;

    // create an empty board
    void init();
    // generate a random, free position on the board
    QVector<int> freePosition();
    // returns true if the current state of the board is different from the argument
    bool changed(Board& other) const;

    bool inbounds(int i, int j);
    // changes state!! (tileCollision & pointsScoredLastRound)
    void moveHorizontally(int i, int j, Direction dir);
    void moveVertically(int i, int j, Direction dir);
    void handleCollision(int i, int j);

    // some reinitalisation for the next round
    void prepareForNextMove();

    int pointsScoredLastRound;
    bool tileCollisionLastRound;
};

#endif // BOARD_H
