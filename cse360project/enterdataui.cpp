#include "enterdataui.h"
#include "ui_enterdataui.h"

#include "Data/UI/pulseratedataui.h"
#include "Data/UI/temperaturedataui.h"
#include "Data/UI/bloodsugardataui.h"
#include "Data/UI/bloodpressuredataui.h"

#include "Data/UI/caloriesdataui.h"
#include "Data/UI/sleepamountdataui.h"
#include "Data/UI/workhoursdataui.h"
#include "Data/UI/cardioworkoutdataui.h"
#include "Data/UI/strengthworkoutdataui.h"

#include "healthtrackerui.h"

EnterDataUI::EnterDataUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterDataUI)
{
    ui->setupUi(this);
}

EnterDataUI::~EnterDataUI()
{
    delete ui;
}

void EnterDataUI::showPulseRateDataUI()
{
    this->close();

    PulseRateDataUI *dataUI = new PulseRateDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showTemperatureDataUI()
{
    this->close();

    TemperatureDataUI *dataUI = new TemperatureDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showBloodSugarDataUI()
{
    this->close();

    BloodSugarDataUI *dataUI = new BloodSugarDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showBloodPressureDataUI()
{
    this->close();

    BloodPressureDataUI *dataUI = new BloodPressureDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showCaloriesDataUI()
{
    this->close();

    CaloriesDataUI *dataUI = new CaloriesDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showSleepAmountDataUI()
{
    this->close();

    SleepAmountDataUI *dataUI = new SleepAmountDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showWorkHoursDataUI()
{
    this->close();

    WorkHoursDataUI *dataUI = new WorkHoursDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showCardioWorkoutDataUI()
{
    this->close();

    CardioWorkoutDataUI *dataUI = new CardioWorkoutDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::showStrengthWorkoutDataUI()
{
    this->close();

    StrengthWorkoutDataUI *dataUI = new StrengthWorkoutDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::cancel()
{
    this->close();

    HealthTrackerUI *healthUI = new HealthTrackerUI();
    healthUI->setVisible(true);
}
