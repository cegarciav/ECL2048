#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include "qgameoverwindow.h"
#include "qwinwindow.h"

#include <QVector>
#include <QWidget>
#include <QMainWindow>

class QResetButton;
class Game;
class QKeyEvent;
class QTile;
class QGridLayout;
class QVBoxLayout;
class QLabel;

class QGameBoard : public QMainWindow
{
    Q_OBJECT
public:
    explicit QGameBoard();
    ~QGameBoard();

    void notify();

private:

    QWidget* main_widget;
    Game* game;
    // gui representation of board
    QVector<QVector<QTile*> > gui_board;
    // main layout
    QVBoxLayout *mainLayout;
    //top score widget
    QLabel *top_score;
    // grid layout of board
    QGridLayout *boardLayout;
    // score widget
    QLabel *score;
    // game over widget
    QGameOverWindow gameOverWindow;
    // winner widget
    QWinWindow win_window;
    bool continuer;

    void drawBoard();

protected:
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:
    void resetGame();

};

#endif // QGAMEBOARD_H
