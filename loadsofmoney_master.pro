#-------------------------------------------------
#
# Project created by QtCreator 2019-09-11T10:35:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loadsofmoney_master
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
        main.cpp \
        mainwindow.cpp \
        questionview.cpp \
    question.cpp \
    gameloop.cpp \
    moneycounter.cpp


HEADERS += \
        mainwindow.h \
        questionview.h \
        question.h \
        gameloop.h \
    moneycounter.h

FORMS += \
        mainwindow.ui \
        questionview.ui \
    moneycounter.ui



RESOURCES += \
    resources.qrc

DISTFILES +=
