#-------------------------------------------------
#
# Project created by QtCreator 2022-04-11T20:40:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chengyuGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        displaywidget.cpp \
        gameutil.cpp \
        main.cpp \
        mainwindow.cpp \
        player.cpp \
        playermanager.cpp \
    npcplayer.cpp \
    humanplayer.cpp \
    statusshowwidget.cpp

HEADERS += \
        constDef.h \
        displaywidget.h \
        gameutil.h \
        mainwindow.h \
        player.h \
        playermanager.h \
    npcplayer.h \
    humanplayer.h \
    statusshowwidget.h

FORMS += \
        mainwindow.ui

DISTFILES +=

RESOURCES += \
    qtRes.qrc
