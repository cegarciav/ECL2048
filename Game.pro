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
    tile.cpp \
    board.cpp \
    game.cpp \
    qgameboard.cpp \
    qtile.cpp \
    qresetbutton.cpp \
    qgameoverwindow.cpp \
    qwinwindow.cpp

HEADERS  += \
    tile.h \
    board.h \
    game.h \
    qgameboard.h \
    qtile.h \
    qresetbutton.h \
    qgameoverwindow.h \
    qwinwindow.h

