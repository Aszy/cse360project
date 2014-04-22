#ifndef STRENGTHWORKOUTDATAUI_H
#define STRENGTHWORKOUTDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class StrengthWorkoutDataUI;
}

class StrengthWorkoutDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit StrengthWorkoutDataUI(QWidget *parent = 0);
    ~StrengthWorkoutDataUI();

public slots:
    void submitData();
    void cancel();

private:
    Ui::StrengthWorkoutDataUI *ui;

    QList<Data *> dataList;
};

#endif // STRENGTHWORKOUTDATAUI_H
