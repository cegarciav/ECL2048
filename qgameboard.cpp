#include "qgameboard.h"
#include "board.h"
#include "game.h"
#include "qtile.h"
#include "tile.h"
#include "qresetbutton.h"

#include <iostream>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>
#include <QWidget>

#include <QDebug>

QGameBoard::~QGameBoard()
{
    delete game;
}

QGameBoard::QGameBoard() :
    QMainWindow()
{
    // set default size
    resize(760,760);
    /*parameter for managing the displaying of
    the winning window after win*/
    continuer = false;
    this->setMinimumSize(600, 600);
    //create the main widget
    main_widget = new QWidget();
    setCentralWidget(main_widget);
    // create the main layout
    mainLayout = new QVBoxLayout();
    main_widget->setLayout(mainLayout);

    // will be created in drawBoard()
    boardLayout = nullptr;

    // create the game and register as observer
    game = new Game(4);
    game->registerObserver(this);

    // create the gui board and draw it
    gui_board.resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        gui_board[i].resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j)
            gui_board[i][j] = nullptr;
    drawBoard();

    // create the top score widget and add it to the board
    top_score = new QLabel(QString("HIGHEST SCORE: %1").arg(game->getHighScore()));
    top_score->setStyleSheet("QLabel { color: rgb(0,153,153); font: 20pt; }"); //Color Score:
    top_score->setFixedHeight(50);
    mainLayout->insertWidget(0, top_score, 0, Qt::AlignLeft);

    // create the score widget and add it to the board
    score = new QLabel(QString("SCORE: %1").arg(game->getScore()));
    score->setStyleSheet("QLabel { color: rgb(0,153,153); font: 20pt; }"); //Color Score:
    score->setFixedHeight(50);
    mainLayout->insertWidget(2, score, 0, Qt::AlignRight);

    // style sheet of the board
    setStyleSheet("QGameBoard { background-color: rgb(132,209,199)}"); //Backgroundcolor

    // connect the event of pressing the restart buttons to the fuction/slot resetGame()
    connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
    connect(win_window.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
}

void QGameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        game->move(UP);
        break;
    case Qt::Key_Left:
        game->move(LEFT);
        break;
    case Qt::Key_Right:
        game->move(RIGHT);
        break;
    case Qt::Key_Down:
        game->move(DOWN);
        break;
    }
}

void QGameBoard::notify()
{
    if (game->isGameOver())
    {
        gameOverWindow.show();
        top_score->setText(QString("SCORE: %1").arg(game->getHighScore()));
    }

    if (game->won() && !continuer)
    {
        win_window.show();
        continuer = true;
    }

    else
        score->setText(QString("SCORE: %1").arg(game->getScore()));

    drawBoard();
}

void QGameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i) {
        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j) {
            delete gui_board[i][j];
            gui_board[i][j] = new QTile(game->getGameBoard()->getTile(i,j));
            boardLayout->addWidget(gui_board[i][j], i, j);
            gui_board[i][j]->draw();
        }
    }
    mainLayout->insertLayout(1, boardLayout);
}


void QGameBoard::resetGame()
{
    game->restart();
    drawBoard();
    score->setText(QString("SCORE: %1").arg(game->getScore()));
    if (gameOverWindow.isVisible())
        gameOverWindow.hide();
    if (win_window.isVisible())
        win_window.hide();
}
