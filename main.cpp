#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <iostream>
#include <question.h>
#include <questionview.h>
#include <gameloop.h>
#include <QFile>
#include <QFontDatabase>
using namespace std;


#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow mainWindow;
    QFontDatabase::addApplicationFont(":/font/open-sans.ttf");
    mainWindow.showFullScreen();

    GameLoop *g = new GameLoop(&mainWindow);
    QObject::connect(mainWindow.getStartButton(), SIGNAL (released()), g, SLOT (startButtonPress()));
    QObject::connect(mainWindow.getQuitButton(), SIGNAL(released()), &a, SLOT(quit()));


    QObject::connect(mainWindow.getQuestionView(), &QuestionView::success, g, &GameLoop::success);

    g->init();
    return a.exec();
}
