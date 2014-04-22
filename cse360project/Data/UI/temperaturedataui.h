#ifndef TEMPERATUREDATAUI_H
#define TEMPERATUREDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class TemperatureDataUI;
}

class TemperatureDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemperatureDataUI(QWidget *parent = 0);
    ~TemperatureDataUI();

public slots:
    void submitData();
    void cancel();

private:
    Ui::TemperatureDataUI *ui;

    QList<Data *> dataList;
};

#endif // TEMPERATUREDATAUI_H
