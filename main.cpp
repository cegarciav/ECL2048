#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "qgameboard.h"

#include "qgameoverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand( (unsigned int) time(nullptr) );
    //srand(time(nullptr));
    QGameBoard board;
    board.show();

    return a.exec();
}
