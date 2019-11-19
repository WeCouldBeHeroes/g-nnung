#ifndef MONEYCOUNTER_H
#define MONEYCOUNTER_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class MoneyCounter;
}

class MoneyCounter : public QWidget
{
    Q_OBJECT

public:
    explicit MoneyCounter(QWidget *parent = nullptr);
    void setIndex(int index);
    void clear();
    ~MoneyCounter();

private:
    QFrame* getElementByInt(int i);
    Ui::MoneyCounter *ui;
};

#endif // MONEYCOUNTER_H
