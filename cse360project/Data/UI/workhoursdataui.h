#ifndef WORKHOURSDATAUI_H
#define WORKHOURSDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class WorkHoursDataUI;
}

class WorkHoursDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkHoursDataUI(QWidget *parent = 0);
    ~WorkHoursDataUI();

public slots:
    void submitData();
    void cancel();

private:
    Ui::WorkHoursDataUI *ui;

    QList<Data *> dataList;
};

#endif // WORKHOURSDATAUI_H
