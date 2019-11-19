#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <question.h>
#include <questionview.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <moneycounter.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QuestionView* getQuestionView();
    QPushButton* getStartButton();
    QLabel* getEndMsg();
    MoneyCounter* getMonyCounter(); 
    QPushButton* getQuitButton();
    void setView(int i);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
