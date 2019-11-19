#include "questionview.h"
#include "ui_questionview.h"
#include <string.h>
#include <iostream>
#include <QFont>
#include <QTimer>
using namespace std;

QuestionView::QuestionView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QuestionView) {
  ui->setupUi(this);

  QFont font(":/font/open-sans.ttf");
  font.setPointSize(14);
  ui->questionLabel->setFont(font);
  ui->a_button->setFont(font);
  ui->b_button->setFont(font);
  ui->c_button->setFont(font);
  ui->d_button->setFont(font);

  connect(ui->a_button, SIGNAL (released()),this, SLOT (buttonClicked1()));
  connect(ui->b_button, SIGNAL (released()),this, SLOT (buttonClicked2()));
  connect(ui->c_button, SIGNAL (released()),this, SLOT (buttonClicked3()));
  connect(ui->d_button, SIGNAL (released()),this, SLOT (buttonClicked4()));
  ui->a_button->setEnabled(false);
  ui->b_button->setEnabled(false);
  ui->c_button->setEnabled(false);
  ui->d_button->setEnabled(false);

}

QPushButton* QuestionView::getButtonByInt(int button) {
    switch (button) {
    case 1:
        return ui->a_button;
    case 2:
        return ui->b_button;
    case 3:
        return ui->c_button;
    case 4:
        return ui->d_button;
    }
}


void QuestionView::all_click(int button,int runround) {
    switch (runround) {
    case 0:
        ui->a_button->setEnabled(false);
        ui->b_button->setEnabled(false);
        ui->c_button->setEnabled(false);
        ui->d_button->setEnabled(false);

        switch (button) {
        case 1:
             getButtonByInt(button)->setStyleSheet("border-image: url(:/images/a_button_enabled.png);" \
                            "border-width: 0px;");
             break;
        case 2:
             getButtonByInt(button)->setStyleSheet("border-image: url(:/images/b_button_enabled.png);" \
                            "border-width: 0px;");
             break;
        case 3:
             getButtonByInt(button)->setStyleSheet("border-image: url(:/images/c_button_enabled.png);" \
                            "border-width: 0px;");
             break;
        case 4:
             getButtonByInt(button)->setStyleSheet("border-image: url(:/images/d_button_enabled.png);" \
                                                                  "border-width: 0px;");
             break;
        }
        QTimer::singleShot(800,this,[this,button,runround]{all_click(button,runround+1);});
        break;
    case 1:
        switch (goodOne) {
        case 1:
             getButtonByInt(goodOne)->setStyleSheet("border-image: url(:/images/a_button_right.png);" \
                            "border-width: 0px;");
             break;
        case 2:
             getButtonByInt(goodOne)->setStyleSheet("border-image: url(:/images/b_button_right.png);" \
                            "border-width: 0px;");
             break;
        case 3:
             getButtonByInt(goodOne)->setStyleSheet("border-image: url(:/images/c_button_right.png);" \
                            "border-width: 0px;");
             break;
        case 4:
             getButtonByInt(goodOne)->setStyleSheet("border-image: url(:/images/d_button_right.png);" \
                                                                  "border-width: 0px;");
             break;
        }
        QTimer::singleShot(500,this,[this,button,runround]{all_click(button,runround+1);});
        break;
    case 2:
        getButtonByInt(button)->setStyleSheet("");
        getButtonByInt(goodOne)->setStyleSheet("");
        if (goodOne == button) {
             emit success(true);
        } else {
             emit success(false);
        }
        break;
    }
}


void QuestionView::buttonClicked1() {
    all_click(1,0);
}

void QuestionView::buttonClicked2() {
    all_click(2,0);
}

void QuestionView::buttonClicked3() {
    all_click(3,0);
}

void QuestionView::buttonClicked4() {
    all_click(4,0);
}

void QuestionView::setQuestion(Question *question) {
    ui->questionLabel->setText(question->getQuestion());
    ui->a_button->setText(question->getAnswer(0));
    ui->b_button->setText(question->getAnswer(1));
    ui->c_button->setText(question->getAnswer(2));
    ui->d_button->setText(question->getAnswer(3));
    goodOne = question->getSolution();
    ui->a_button->setEnabled(true);
    ui->b_button->setEnabled(true);
    ui->c_button->setEnabled(true);
    ui->d_button->setEnabled(true);
}


QuestionView::~QuestionView() {
  delete ui;
}
