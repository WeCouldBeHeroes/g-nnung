#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <question.h>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font(":/font/open-sans.ttf");
    font.setPointSize(14);
    ui->endMsg->setText("");
    ui->endMsg->setFont(font);
    ui->startButton->setFont(font);
    ui->moneycounter->setFont(font);
    ui->stackedWidget->setCurrentIndex(0);

}

QPushButton* MainWindow::getQuitButton() {
    return ui->quitButton;
}

MoneyCounter* MainWindow::getMonyCounter() {
    return ui->moneycounter;
}

QuestionView* MainWindow::getQuestionView() {
    return ui->questionView;
}

void MainWindow::setView(int i) {
    ui->stackedWidget->setCurrentIndex(i);
}

QPushButton* MainWindow::getStartButton() {
    return ui->startButton;
}

QLabel* MainWindow::getEndMsg() {
    return ui->endMsg;
}


MainWindow::~MainWindow()
{
    delete ui;
}
