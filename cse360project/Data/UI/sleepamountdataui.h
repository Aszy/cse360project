#ifndef SLEEPAMOUNTDATAUI_H
#define SLEEPAMOUNTDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class SleepAmountDataUI;
}

class SleepAmountDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit SleepAmountDataUI(QWidget *parent = 0);
    ~SleepAmountDataUI();

public slots:
    void submitData();
    void cancel();

private:
    Ui::SleepAmountDataUI *ui;

    QList<Data *> dataList;
};

#endif // SLEEPAMOUNTDATAUI_H
