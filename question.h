#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <QStringList>
#include <QString>
#include <QObject>
using namespace std;

class Question {

public:
    Question();
    void generateQuestion(QString question,QString answer1,QString answer2, QString answer3,QString answer4,int solution, int difficulty);
    QString getAnswer(int i);
    QString getQuestion();
    int getSolution();
    ~Question();
private:
    QString question = "What is my name?";
    QStringList *answers = new QStringList();
    int solution = 3;
    int difficulty = 0;
};

#endif // QUESTION_H
