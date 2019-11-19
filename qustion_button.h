#ifndef QUSTION_BUTTON_H
#define QUSTION_BUTTON_H

#include <QWidget>

namespace Ui {
    class qustion_button;
}

class qustion_button : public QWidget
{
    Q_OBJECT

public:
    explicit qustion_button(QWidget *parent = nullptr);
    ~qustion_button();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::qustion_button *ui;
};

#endif // QUSTION_BUTTON_H
