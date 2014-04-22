#ifndef CARDIOWORKOUTDATAUI_H
#define CARDIOWORKOUTDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class CardioWorkoutDataUI;
}

class CardioWorkoutDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CardioWorkoutDataUI(QWidget *parent = 0);
    ~CardioWorkoutDataUI();

public slots:
    void updateRunSpeed();
    void submitData();
    void cancel();

private:
    Ui::CardioWorkoutDataUI *ui;

    QList<Data *> dataList;
};

#endif // CARDIOWORKOUTDATAUI_H
