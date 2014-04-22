#ifndef BLOODPRESSUREDATAUI_H
#define BLOODPRESSUREDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class BloodPressureDataUI;
}

class BloodPressureDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BloodPressureDataUI(QWidget *parent = 0);
    ~BloodPressureDataUI();

public slots:
    void submitData();
    void cancel();

private:
    Ui::BloodPressureDataUI *ui;

    QList<Data *> dataList;
};

#endif // BLOODPRESSUREDATAUI_H
