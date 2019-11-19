#include "qustion_button.h"
#include "ui_qustion_button.h"

qustion_button::qustion_button(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qustion_button)
{
    ui->setupUi(this);

}


qustion_button::mouseReleaseEvent(QMouseEvent *event) {

}

qustion_button::~qustion_button()
{
    delete ui;
}
