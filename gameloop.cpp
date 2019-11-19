#include "gameloop.h"
#include "QObject"
#include <qfile.h>
#include "stdint.h"
#include <stdlib.h>
#include <stdio.h>
#include "iostream"
#include <cstring>
#include <QTimer>
#include <qstring.h>
#include <time.h>

GameLoop::GameLoop(MainWindow *mainWindow) : QObject() {
    this->mainWindow = mainWindow;
}


void GameLoop::init() {

}

void GameLoop::askQuestion(int round) {
    mainWindow->getMonyCounter()->setIndex(round);
    Question q = getQuestion(round);
    mainWindow->getQuestionView()->setQuestion(&q);
}

void GameLoop::gameloop(int round,bool lost) {
    if (lost) {
      gameEnd(lost);
    }else if (round > 14) {
      mainWindow->getMonyCounter()->setIndex(round);
      QTimer::singleShot(800,this,[this,lost]{ gameEnd(lost);});

    } else {
       askQuestion(round);
    }
}


void GameLoop::gameEnd(bool lost) {
    round = 0;
    if (lost) {
         mainWindow->getEndMsg()->setText("You suck man");
    } else {

         mainWindow->getEndMsg()->setText("GEWONNEN YUHU");
    }
    mainWindow->setView(0);
    mainWindow->getMonyCounter()->clear();
}



void GameLoop::success(bool status) {
    round++;
    gameloop(round,!status);
}


void GameLoop::startButtonPress() {
    mainWindow->setView(1);
    mainWindow->getEndMsg()->setText("");
    gameloop(0,false);
}

Question GameLoop::getQuestion(int round) {
    Question *q = new Question();
    srand(time(0));
    int random;
    int wert;
    bool check;

    do{
        random=rand()%20;
        check=true;
        for(int x=0;x>15;x++)
        {
            wert=rundenfragen[x];
            if(random==wert)
            {
                check=false;
                break;
            }
        }

    }while(check==false);
    rundenfragen[round]=random;

    q->generateQuestion(fragen[random][0],fragen[random][1],fragen[random][2],fragen[random][3],fragen[random][4],fragen[random][5].toInt(),round);
    return *q;
}

GameLoop::~GameLoop() {

}
