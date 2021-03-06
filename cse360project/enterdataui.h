#ifndef ENTERDATAUI_H
#define ENTERDATAUI_H

#include <QDialog>
#include "Data/data.h"

namespace Ui {
class EnterDataUI;
}

class EnterDataUI : public QDialog
{
    Q_OBJECT

public:
    explicit EnterDataUI(QWidget *parent = 0);
    ~EnterDataUI();

public slots:
    void showPulseRateDataUI();
    void showTemperatureDataUI();
    void showBloodSugarDataUI();
    void showBloodPressureDataUI();

    void showCaloriesDataUI();
    void showSleepAmountDataUI();
    void showWorkHoursDataUI();
    void showCardioWorkoutDataUI();
    void showStrengthWorkoutDataUI();

    void cancel();

private:
    Ui::EnterDataUI *ui;
};

#endif // ENTERDATAUI_H
