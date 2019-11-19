#include "moneycounter.h"
#include "ui_moneycounter.h"

int position = 0;

MoneyCounter::MoneyCounter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoneyCounter)
{
    ui->setupUi(this);

}

QFrame* MoneyCounter::getElementByInt(int i) {
    switch (i) {
    case 1:
        return ui->stage1;
    case 2:
        return ui->stage2;
    case 3:
        return ui->stage3;
    case 4:
        return ui->stage4;
    case 5:
        return ui->stage5;
    case 6:
        return ui->stage6;
    case 7:
        return ui->stage7;
    case 8:
        return ui->stage8;
    case 9:
        return ui->stage9;
    case 10:
        return ui->stage10;
    case 11:
        return ui->stage11;
    case 12:
        return ui->stage12;
    case 13:
        return ui->stage13;
    case 14:
        return ui->stage14;
    case 15:
        return ui->stage15;
    }
    return ui->stage1;
}

void MoneyCounter::setIndex(int index) {
    if (index != 0) {
       getElementByInt(position)->setEnabled(false);
       getElementByInt(index)->setEnabled(true);

       position = index;
    }

}

void MoneyCounter::clear() {
    if (position != 0) {
        getElementByInt(position)->setEnabled(false);
    }
}

MoneyCounter::~MoneyCounter()
{
    delete ui;
}
