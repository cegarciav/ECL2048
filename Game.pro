#-------------------------------------------------
#
# Project created by QtCreator 2019-03-19T18:23:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    tile.cpp \
    board.cpp \
    game.cpp \
    qgameboard.cpp \
    qtile.cpp \
    qresetbutton.cpp \
    observer.cpp \
    subject.cpp \
    qgameoverwindow.cpp

HEADERS  += mainwindow.h \
    tile.h \
    board.h \
    game.h \
    qgameboard.h \
    qtile.h \
    qresetbutton.h \
    observer.h \
    subject.h \
    qgameoverwindow.h \
    qwinwindow.h

