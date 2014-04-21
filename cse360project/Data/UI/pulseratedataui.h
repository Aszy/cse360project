#ifndef PULSERATEDATAUI_H
#define PULSERATEDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class PulseRateDataUI;
}

class PulseRateDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit PulseRateDataUI(QWidget *parent = 0);
    ~PulseRateDataUI();

public slots:
    void submitPulseRateData();
    void cancel();

private:
    Ui::PulseRateDataUI *ui;

    QList<Data *> dataList;
};

#endif // PULSERATEDATAUI_H
