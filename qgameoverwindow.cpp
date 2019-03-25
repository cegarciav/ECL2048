#include "qgameoverwindow.h"
#include "qresetbutton.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>

QGameOverWindow::QGameOverWindow(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("QGameOverWindow { background: rgb(132,209,199); }"); //237,224,200
    setFixedSize(525,405);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: rgb(0,153,153); font: 30pt; font: bold;} "); //119,110,101
    // reset button
    reset = new QResetButton(this);
    reset->setFixedHeight(80);
    reset->setFixedWidth(230);
    // add game over label to window
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
    // add reset button to window
    layout->insertWidget(1,reset,0,Qt::AlignCenter);
}

QResetButton* QGameOverWindow::getResetBtn() const
{
    return reset;
}
