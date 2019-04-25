#include "qwinwindow.h"
#include "qresetbutton.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QResizeEvent>

QWinWindow::QWinWindow(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("QWinWindow { background: rgb(132,209,199); }");
    setFixedSize(525,405);
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *hlayout1 = new QHBoxLayout();
    QHBoxLayout *hlayout2 = new QHBoxLayout();
    // game over label
    gamewon = new QLabel("Tu as reussi le 2048, félicitacion!\n Tu peux continuer le jeu pour augmenter ta score");
    gamewon->setWordWrap(true);
    gamewon->setStyleSheet("QLabel { color: rgb(0,153,153); font: 30pt; font: bold;} ");
    gamewon->setAlignment(Qt::AlignCenter);
    // reset button
    reset_button = new QResetButton();
    reset_button->setFixedHeight(80);
    reset_button->setFixedWidth(230);
    // continuer button
    continuer_button = new QPushButton();
    continuer_button->setFixedHeight(80);
    continuer_button->setFixedWidth(230);
    continuer_button->setText("Continuer");
    continuer_button->setStyleSheet("QPushButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; }");
    connect(continuer_button, SIGNAL (clicked()),this, SLOT (continuer_option()));
    // add elements to the window
    hlayout1->addWidget(gamewon);
    hlayout2->addWidget(continuer_button);
    hlayout2->addWidget(reset_button);
    layout->addLayout(hlayout1);
    layout->addLayout(hlayout2);

}

void QWinWindow::continuer_option()
{
    this->hide();
}


QResetButton* QWinWindow::getResetBtn() const
{
    return reset_button;
}
