#include "game.h"
#include "tile.h"

#include <fstream>
#include <string>

using namespace std;

Game::Game(int dimension)
{
    score = 0;
    readHighScore();
    board = new Board(dimension);
    restart();
}

Game::~Game()
{
    delete board;
}


void Game::registerObserver(QGameBoard* observer)
{
    board->registerObserver(observer);
}


void Game::move(Direction dir)
{
    // do the move
    board->move(dir);

    // update score
    if (board->isTileCollisionLastRound())
        score += board->getPointsScoredLastRound();

    // if there is no more move possible, then it's game over
    if (!board->movePossible())
    {
        gameOver = true;
        saveHighScore();
    }

    board->notifyObservers();
}

void Game::restart()
{
    board->reset();
    gameOver = false;
    score = 0;
    readHighScore();
}

// alternative (and more efficient implementation):
// keep a variable win in Board,
// everytime tiles collide check if the upgrade results in a value of WINNING_VALUE
bool Game::won() const
{
    for (int i = 0; i < board->getDimension(); ++i)
        for (int j = 0; j < board->getDimension(); ++j)
            if (board->getTile(i,j) != nullptr && board->getTile(i,j)->getValue() == WINNING_VALUE)
                return true;

    return false;
}


void Game::readHighScore()
{
    try {
        string current_score;
        ifstream doc_topscore("highscore", ios::in);
        getline(doc_topscore, current_score);
        highscore = stoi(current_score);
        doc_topscore.close();
    } catch (...) {
        highscore = 0;
    }
}


void Game::saveHighScore()
{
    if (score > highscore)
    {
        highscore = score;
        ofstream doc_topscore("highscore", ios::trunc);
        doc_topscore << highscore;
        doc_topscore.close();
    }
}
